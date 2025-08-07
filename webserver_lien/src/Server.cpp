/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                   	    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitran<thitran@student.42nice.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:26:13 by thitran           #+#    #+#             */
/*   Updated: 2025/08/04 13:52:34 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include <iostream>
#include <sstream>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <algorithm>
#include <fstream>
#include <cerrno>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>


#define BUFFER_SIZE 4096

// Helper function to print error to stderr using allowed functions
static void print_error(const char* msg) {
    const char* err = strerror(errno);
    write(2, msg, strlen(msg));
    write(2, ": ", 2);
    write(2, err, strlen(err));
    write(2, "\n", 1);
}

Server::Server() {}

Server::~Server() {
    for (size_t i = 0; i < _sockets.size(); ++i) {
        close(_sockets[i]);
    }
    for (std::map<int, Client>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
        close(it->first);
    }
}

bool Server::addPort(int port) {
    _ports.push_back(port);
    return true;
}

bool Server::setup() {
    for (size_t i = 0; i < _ports.size(); ++i) {
        if (!createSocket(_ports[i])) return false;
    }
    return true;
}

bool Server::createSocket(int port) {
	sockaddr_in	server_addr;

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        print_error("socket");
        return false;
    }

    fcntl(server_fd, F_SETFL, O_NONBLOCK);

	std::memset(&server_addr, 0, sizeof(server_addr));

    struct sockaddr_in addr;
    // Manual memset replacement
    char* p = (char*)&addr;
    for (size_t i = 0; i < sizeof(addr); ++i)
        p[i] = 0;

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        print_error("bind");
        close(server_fd);
        return false;
    }

    if (listen(server_fd, 100) < 0) {
        print_error("listen");
        close(server_fd);
        return false;
    }

    std::cout << "Listening on port " << port << std::endl;

    struct pollfd pfd;
    pfd.fd = server_fd;
    pfd.events = POLLIN;
    _pollfds.push_back(pfd);
    _sockets.push_back(server_fd);

    return true;
}

void Server::run() {
    while (true) {
        int ret = poll(&_pollfds[0], _pollfds.size(), -1);
        if (ret < 0) {
            print_error("poll");
            break;
        }

        for (size_t i = 0; i < _pollfds.size(); ++i) {
            if (_pollfds[i].revents & POLLIN) {
                int fd = _pollfds[i].fd;

                // Check if it’s a server socket (new connection)
                if (std::find(_sockets.begin(), _sockets.end(), fd) != _sockets.end()) {
                    acceptNewConnection(fd);
                } else {
                    handleClientData(fd);
                }
            }
        }
    }
}

void Server::acceptNewConnection(int server_fd) {
    int client_fd = accept(server_fd, NULL, NULL);
    if (client_fd < 0) {
        print_error("accept");
        return;
    }

    struct pollfd pfd;
    pfd.fd = client_fd;
    pfd.events = POLLIN;
    _pollfds.push_back(pfd);

    _clients[client_fd] = Client(client_fd);

    std::cout << "New connection: fd " << client_fd << std::endl;
}

void Server::handleClientData(int client_fd) {
    char buf[BUFFER_SIZE];
    int bytes = recv(client_fd, buf, BUFFER_SIZE, 0);
    if (bytes <= 0) {
        closeClient(client_fd);
        return;
    }

    Client &client = _clients[client_fd];
    client.getBuffer().append(buf, bytes);

    if (client.parseRequest()) {
        Request &req = client.getRequest();
        Response &res = client.getResponse();

        std::string uri = req.getURI();
        std::string method = req.getMethod();

        // Check if URI ends with .php or .py for CGI handling
        if (uri.size() > 4) {
            std::string extension = uri.substr(uri.size() - 4);
            std::string scriptPath = "www" + uri; // Path to CGI script

            if (extension == ".php") {
                runCgi(scriptPath, "/usr/bin/php-cgi", client_fd);
                closeClient(client_fd);
                return;
            } else if (extension == ".py") {
                runCgi(scriptPath, "/usr/bin/python3", client_fd);
                closeClient(client_fd);
                return;
            }
        }

/*
        // PHP file
        if (uri.size() > 4 && uri.substr(uri.size() - 4) == ".php") {
            std::string scriptPath = "www" + uri; // Path to PHP file
            runPhpCgi(scriptPath.c_str(), client_fd);
            closeClient(client_fd);
            return;
        }

        // Python file
        if (uri.size() > 3 && uri.substr(uri.size() - 3) == ".py") {
            std::string scriptPath = "www" + uri; // Path to Python file
            runPythonCgi(scriptPath.c_str(), client_fd);
            closeClient(client_fd);
            return;
        }
*/
        if (method == "GET") {
            // Simulate Internal Server Error
            if (uri == "/cause500") {
                res.setDefaultErrorBody(500);
            } else {
                std::string path = "www" + uri;
                if (uri == "/") path = "www/index.html";

                std::ifstream file(path.c_str());
                if (file.is_open()) {
                    std::ostringstream ss;
                    ss << file.rdbuf();
                    res.setStatus(200);
                    res.setContentType("text/html");
                    res.setBody(ss.str());
                } else {
                    res.setDefaultErrorBody(404);
                }
            }
        }
        else if (method == "POST") {
            std::string body = req.getBody();
            std::string content_type = req.getHeader("Content-Type");

            if (content_type.find("multipart/form-data") != std::string::npos) {
                size_t pos = content_type.find("boundary=");
                if (pos != std::string::npos) {
                    std::string boundary = "--" + content_type.substr(pos + 9);
                    size_t start = 0;
                    std::string response_body;
                    // *** Removed mkdir call: make sure "www/uploads" directory exists manually ***

                    while ((start = body.find(boundary, start)) != std::string::npos) {
                        size_t header_end = body.find("\r\n\r\n", start);
                        if (header_end == std::string::npos) break;

                        std::string headers = body.substr(start, header_end - start);
                        size_t filename_pos = headers.find("filename=\"");

                        if (filename_pos != std::string::npos) {
                            size_t start_filename = filename_pos + 10;
                            size_t end_filename = headers.find("\"", start_filename);
                            std::string filename = headers.substr(start_filename, end_filename - start_filename);

                            if (!filename.empty()) {
                                size_t content_start = header_end + 4;
                                size_t next_boundary = body.find(boundary, content_start);
                                if (next_boundary == std::string::npos) break;

                                size_t content_end = next_boundary;
                                // Remove trailing CRLF
                                if (body[content_end - 2] == '\r' && body[content_end - 1] == '\n') {
                                    content_end -= 2;
                                }

                                std::string filepath = "www/uploads/" + filename;
                                std::ofstream out(filepath.c_str(), std::ios::binary);
                                if (out.is_open()) {
                                    out.write(&body[content_start], content_end - content_start);
                                    out.close();
                                    response_body += "<p>Uploaded: " + filename + "</p>\n";
                                } else {
                                    response_body += "<p>Failed to save: " + filename + "</p>\n";
                                }
                            }
                        }

                        // Move to next part
                        start = body.find(boundary, start + boundary.length());
                    }

                    res.setStatus(201);
                    res.setBody("<h1>Upload Result</h1>\n" + response_body);
                } else {
                    res.setStatus(400);
                    res.setBody("<h1>Bad Request: No boundary found</h1>");
                }
            } else {
                res.setStatus(400);
                res.setBody("<h1>Bad Request: Expected multipart/form-data</h1>");
            }

            res.setContentType("text/html");
        }
        else if (method == "DELETE") {
            std::string path = "www" + uri;
            if (remove(path.c_str()) == 0) {
                res.setStatus(200);
                res.setBody("<h1>File deleted</h1>");
            } else {
                res.setDefaultErrorBody(404);
            }
            res.setContentType("text/html");
        }
        else {
            res.setDefaultErrorBody(405); // Method Not Allowed
        }

        std::string output = res.build();
        send(client_fd, output.c_str(), output.size(), 0);
        closeClient(client_fd); // For simplicity: one request per connection
    }
}

void Server::closeClient(int client_fd) {
    std::cout << "Closing client fd: " << client_fd << std::endl;
    close(client_fd);
    _clients.erase(client_fd);

    for (size_t i = 0; i < _pollfds.size(); ++i) {
        if (_pollfds[i].fd == client_fd) {
            _pollfds.erase(_pollfds.begin() + i);
            break;
        }
    }
}

void Server::setConfig(const Config* config) {
    const std::vector<int>& ports = config->getPorts();
    for (size_t i = 0; i < ports.size(); ++i) {
        addPort(ports[i]);
    }
}

void Server::runCgi(const std::string& scriptPath, const std::string& interpreter, int client_fd) {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        print_error("pipe");
        return;
    }

    pid_t pid = fork();
    if (pid < 0) {
        print_error("fork");
        return;
    }

    if (pid == 0) {
        // Child process
        close(pipefd[0]); // Close read end

        // Redirect stdout to pipe write end
        if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
            print_error("dup2");
            exit(1);
        }
        close(pipefd[1]);

        // Redirect stderr to stdout to capture errors
        if (dup2(STDOUT_FILENO, STDERR_FILENO) == -1) {
            print_error("dup2 stderr");
            exit(1);
        }

        // Execute interpreter with script path as argument
        execlp(interpreter.c_str(), interpreter.c_str(), scriptPath.c_str(), NULL);

        // If execlp fails
        print_error("execlp");
        exit(1);
    } else {
        // Parent process
        close(pipefd[1]); // Close write end

        char buffer[BUFFER_SIZE];
        ssize_t count;
        std::string output;

        // Read all output from the child process
        while ((count = read(pipefd[0], buffer, BUFFER_SIZE)) > 0) {
            output.append(buffer, count);
        }
        close(pipefd[0]);

        // Wait for child process to finish
        int status;
        waitpid(pid, &status, 0);

        // Build HTTP response manually (assuming CGI returns full HTTP headers)
        if (!output.empty()) {
            send(client_fd, output.c_str(), output.size(), 0);
        } else {
            // If no output, send 500 Internal Server Error
            std::string error_body =
                "HTTP/1.1 500 Internal Server Error\r\n"
                "Content-Type: text/html\r\n\r\n"
                "<h1>500 Internal Server Error</h1>\n";
            send(client_fd, error_body.c_str(), error_body.size(), 0);
        }
    }
}

/*
void Server::runPhpCgi(const char* scriptPath, int client_fd) {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        print_error("pipe");
        return;
    }

    pid_t pid = fork();
    if (pid < 0) {
        print_error("fork");
        return;
    }

    if (pid == 0) { // Child process
        if (close(pipefd[0]) == -1) {
            print_error("close pipefd[0] in child");
            _exit(1);
        }

        if (dup2(pipefd[1], 1) == -1) {
            print_error("dup2");
            _exit(1);
        }

        if (close(pipefd[1]) == -1) {
            print_error("close pipefd[1] in child");
            _exit(1);
        }

        const char* argv[3];
        argv[0] = "php-cgi";
        argv[1] = scriptPath;
        argv[2] = NULL;

        extern char **environ;
        execve("/usr/bin/php-cgi", (char* const*)argv, environ);

        // execve only returns on error
        print_error("execve");
        _exit(1);
    } else { // Parent process
        if (close(pipefd[1]) == -1) {
            print_error("close pipefd[1] in parent");
            return;
        }

        char buffer[4096];
        ssize_t bytesRead;
        while ((bytesRead = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
            ssize_t bytesSent = 0;
            while (bytesSent < bytesRead) {
                ssize_t ret = send(client_fd, buffer + bytesSent, bytesRead - bytesSent, 0);
                if (ret == -1) {
                    print_error("send");
                    close(pipefd[0]);
                    return;
                }
                bytesSent += ret;
            }
        }
        if (bytesRead == -1) {
            print_error("read");
        }

        if (close(pipefd[0]) == -1) {
            print_error("close pipefd[0] in parent");
        }

        int status;
        waitpid(pid, &status, 0);
    }
}

void Server::runPythonCgi(const char* scriptPath, int client_fd) {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        print_error("pipe");
        return;
    }

    pid_t pid = fork();
    if (pid < 0) {
        print_error("fork");
        return;
    }

    if (pid == 0) { // Child
        close(pipefd[0]); // Close read end

        // Redirect stdout to pipe write end
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        // Execute Python interpreter on scriptPath
        execl("/usr/bin/python3", "python3", scriptPath, NULL);

        // If exec fails
        print_error("execl");
        _exit(1);
    } else { // Parent
        close(pipefd[1]); // Close write end

        char buffer[BUFFER_SIZE];
        ssize_t count;
        std::string output;

        // Read output from pipe
        while ((count = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
            output.append(buffer, count);
        }
        close(pipefd[0]);

        // Wait for child to finish
        int status;
        waitpid(pid, &status, 0);

        // Send output to client
        send(client_fd, output.c_str(), output.size(), 0);
    }
}
*/