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
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

void Server::handleClientWrite(Client *client)
{
    Response &res = client->getResponse();
    size_t CHUNK_SIZE = 4 * 1024 * 1024;
    ssize_t byteSend = 0;
    size_t toSend;
    if (res._indexByteSend == 0) {
        size_t preview_size = 100;
        std::cout << "=====Preview=====" << std::endl;
        std::cout << res.output.substr(0, std::min(preview_size, res.output.size())) << std::endl;
    }
    if (res.headerByteSize > res._indexByteSend) {
        toSend = std::min(CHUNK_SIZE, res.headerByteSize  - res._indexByteSend);
    } else if (!res.sendFile){
        size_t bodySent = res._indexByteSend - res.headerByteSize;
        size_t bodyLeft = res._outputLength - res.headerByteSize - bodySent;
        toSend = std::min(CHUNK_SIZE, bodyLeft);
    } else {
        if (client->write_fd == -1) {
            client->write_fd = open(client->writePath.c_str(), O_RDONLY);
            if (client->write_fd == -1) {
                perror("open");
                return;
            }
            if (client->bodyOffSet > 0) {
                if (lseek(client->write_fd, client->bodyOffSet, SEEK_SET) == -1) {
                    perror("lseek");
                    close(client->write_fd);
                    return;
                }
            }
        }
        std::vector<char> buffer(CHUNK_SIZE);
        ssize_t bytesReader = read(client->write_fd, &buffer[0], sizeof(buffer));
        if (bytesReader)  {
            byteSend = send(client->client_fd, &buffer[0], bytesReader, 0);
        } else {
            close(client->write_fd);
            client->write_fd = -1;
            return;
        }
    }
    byteSend = send(
        client->client_fd,
        res.output.c_str() + res._indexByteSend,
        toSend,
        0);
    if (byteSend > 0) { res._indexByteSend += byteSend; }
    if (byteSend == -1) { return; }
    if (byteSend > 0) {  std::cout << "\rTotalByteSend: " << res._indexByteSend << std::flush; }
    if (res._indexByteSend >= res._outputLength && !byteSend) { client->state = COMPLETED; }
    
}

Server::Server() {}

Server::~Server()
{
    /* for (size_t i = 0; i < _sockets.size(); ++i) {
        close(_sockets[i]);
    } */
    /* for (std::map<int, Client>::iterator it = _clients.begin(); it != _clients.end(); ++it)
    {
        close(it->first);
    } */
    /* for (std::map<int, Connect *>::iterator it = _connects.begin(); it != _connects.end(); ++it)
    {
        delete it->second;
    } */
}

bool Server::setup(Config &config)
{

    std::vector<ServerConfig> &t = config.getServers();

    std::set<int> init_port;

    for (size_t i = 0; i < t.size(); ++i)
        init_port.insert(t[i].port);

    for (std::set<int>::iterator it = init_port.begin(); it != init_port.end(); ++it)
    {
        int server_fd = this->createSocket(*it);
        if (server_fd > 0)
        {
            for (size_t i = 0; i < t.size(); ++i)
            {
                if (t[i].port == *it)
                {
                    t[i].server_fd = server_fd;
                    this->_connects.push_back(&t[i]);
                    for (size_t at = 0; at < t[i].locations.size(); ++at)
                    {
                        if (t[i].locations[at].port == *it)
                        {
                            t[i].locations[at].port = *it;
                        }
                    }
                }
            }
        }
    }

    return true;
}

int Server::createSocket(int port)
{
    sockaddr_in addr;

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0)
    {
        std::cerr << "Error: Socket on port: " << port << std::endl;
        return 0;
    }

    fcntl(server_fd, F_SETFL, O_NONBLOCK);

    std::memset(&addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        std::cerr << "Error: Fail to bind port: " << port << std::endl;
        close(server_fd);
        return 0;
    }

    if (listen(server_fd, 100) < 0)
    {
        std::cerr << "Error: Fail to listen port: " << port << std::endl;
        close(server_fd);
        return 0;
    }

    std::cout << "Listening on port " << port << std::endl;

    struct pollfd pfd;
    pfd.fd = server_fd;
    pfd.events = POLLIN;
    pfd.revents = 0;

    this->_fds.push_back(pfd);
    this->_sockets.insert(server_fd);

    return server_fd;
}

Client *Server::findByClientFd(const int client_fd)
{
    return this->_clients[client_fd];
}

bool Server::removeClientByFd(const int client_fd)
{
    Client *client = this->findByClientFd(client_fd);
    delete client;
    this->_clients.erase(client_fd);
    return false;
}

LocationConfig *Server::getServerConfig(Client *client)
{
    size_t maxLength = 0;
    LocationConfig *bestLocation;
    for (size_t at = 0; at < this->_connects.size(); ++at)
    {
        ServerConfig *config = this->_connects[at];
        if (config->server_fd == client->server_fd && config->server_name == client->getRequest().getHostname())
        {
            for (size_t it = 0; it < config->locations.size(); ++it)
            {

                std::string locationPath = config->locations[it].path;
                std::string requestURI = client->getRequest().getURI();

                if (requestURI.size() > 1 && requestURI[requestURI.size() - 1] == '/')
                    requestURI.erase(requestURI.size() - 1);

                if (locationPath.size() > 1 && locationPath[locationPath.size() - 1] == '/')
                    locationPath.erase(locationPath.size() - 1);

                if (!requestURI.compare(0, locationPath.size(), locationPath))
                {
                    if (requestURI.size() == locationPath.size() || requestURI[locationPath.size()] == '/')
                    {
                        if (locationPath.size() > maxLength)
                        {
                            bestLocation = &config->locations[it];
                            maxLength = locationPath.size();
                        }
                    }
                }
            }
        }
    }

    return bestLocation;
}

void Server::switchEvents(int client_fd, std::string type)
{
    if (type == "POLLOUT")
    {
        for (size_t i = 0; i < _fds.size(); ++i)
        {
            if (_fds[i].fd == client_fd)
            {
                _fds[i].events |= POLLOUT;
                _fds[i].events &= ~POLLIN;
                return;
            }
        }
    }
}

bool Server::_isAllowedMethod(std::vector<std::string> allowed_methods, std::string method)
{
    if (allowed_methods.empty() && method == "GET")
        return true;
    if (std::find(allowed_methods.begin(), allowed_methods.end(), method) == allowed_methods.end())
        return false;
    return true;
}

void Server::acceptNewConnection(int server_fd)
{
    struct sockaddr_in client_addr;

    socklen_t client_len = sizeof(client_addr);
    int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);

    if (client_fd < 0)
        return;

    fcntl(client_fd, F_SETFL, O_NONBLOCK);

    struct pollfd pfd;
    pfd.fd = client_fd;
    pfd.events = POLLIN;
    pfd.revents = 0;

    std::cout << "Connected:" << inet_ntoa(client_addr.sin_addr) << std::endl;

    this->_clients[client_fd] = new Client(client_fd, server_fd);

    this->_fds.push_back(pfd);
}

void Server::run()
{
    std::remove("/tmp/cgi_input");
    while (true)
    {
        int ret = poll(&_fds[0], _fds.size(), -1);
        if (ret <= 0)
            continue;
        for (size_t i = 0; i < _fds.size(); i++)
        {
            int fd = _fds[i].fd;

            Client *client = this->findByClientFd(_fds[i].fd);

            WriteIt it = _writeJobs.find(fd);

            if (_fds[i].revents & POLLIN)
            {
                if (this->_sockets.count(fd))
                {
                    acceptNewConnection(fd);
                }
                else if (it != _writeJobs.end())
                {
                    client = this->findByClientFd(it->second);
                    client->writeFile();
                    if (client->writingFile) {
                        closeConnection(client->write_fd);
                    }
                }
                else
                {
                    handleClientData(client);
                }
            }

            if (_fds[i].revents & POLLOUT) { handleClientWrite(client); }

            if (client && client->state == COMPLETED)
            {
                if (_fds[i].revents & POLLHUP)
                {
                    closeConnection(client->client_fd);
                }
            }
        }
    }
}

void Server::handleClientData(Client *client)
{

    client->receive();

    if (client->state == COMPLETED)
    {
        return closeConnection(client->client_fd);
    }

    Request &request = client->getRequest();

    Response &response = client->getResponse();

    if (client->state == HEADER)
    {
        if (client->parseHeader() && !client->location)
        {
            client->location = this->getServerConfig(client);
        }

        if (client->location)
        {
            if (!request.hasBody) { client->state = METHOD; }
            if (request.hasBody) { client->state = BODY; }
            if (!_isAllowedMethod(client->location->allowed_methods, request.getMethod()))
            {
                response.setDefaultErrorBody(405);
                response.build();
                client->state = RESPONSE;
            }
        }
    }

    if (client->state == BODY)
    {
        switch (client->parseBody(client->location->maxBodySize))
        {
            case 0: { client->state = METHOD; } break;
            case 2:
            {
                response.setDefaultErrorBody(413);
                response.build();
                client->state = RESPONSE;
            }
            break;
        }
    }
    

    if (client->state == METHOD)
    {
        std::string path;
        std::string uri = request.getURI();
        std::string method = request.getMethod();
        std::string temp = client->location->path;
        if (temp != "/" && temp[0] == '/'){
            temp = client->location->path.substr(1);
            path = client->location->root + uri.substr(temp.size());
        }
        else { path = uri; }
        if (uri.size() > 4) {
            client->hasCGI = true;
            std::string extension = uri.substr(uri.size() - 4);
            std::string scriptPath = "www" + uri;
            if (extension == ".php")
                runCgi( client, scriptPath, "/usr/bin/php-cgi", "");
            else if (extension == ".py")
                runCgi(client, scriptPath, "/usr/bin/python3", "");
            else if (extension == ".bla" && method == "POST")
            {
                struct stat st;
                if (stat("/tmp/cgi_input", &st) == 0) {
                    std::cout << std::endl << "St_size: " <<  st.st_size << std::endl;
                }
                runCgi(
                    client,
                    "/home/bernardoalbuquerque/Documentos/code42/code42_git/webser_lien_config/YoupiBanane/ubuntu_cgi_tester",
                    "",
                    "/tmp/cgi_input"
                );
                std::remove("/tmp/cgi_input");
            }
        }

        if (method == "GET")
        {
            if (uri == "/cause500")
                response.setDefaultErrorBody(500);
            else
            {
                if (uri == "/")
                    path = client->location->root + client->location->index;

                /*  std::cout << "DEBUGG:333:path: " << path << std::endl; */

                if (_isDirectory(std::string("./") + path))
                {
                    if (path[path.size() - 1] != '/' && client->location->index[client->location->index.size() - 1] != '/')
                        path = path + std::string("/") + client->location->index;
                    else
                        path = path + client->location->index;
                }

                std::ifstream file(path.c_str());
                if (file.is_open())
                {
                    std::ostringstream ss;
                    ss << file.rdbuf();
                    response.setStatus(200);
                    response.setContentType("text/html");
                    response.setBody(ss.str());
                }
                else
                {
                    response.setDefaultErrorBody(404);
                }
            }
        }


        if (method == "POST")
        {
            std::string content_type = request.getHeader("Content-Type");
            if (client->hasCGI)
            {
                
                int fd = open(client->writePath.c_str(), O_RDONLY);
                // HANDLE OPEN FILE ERROR;
                if (fd == -1) { };
                
                char buffer[4096];
                std::string headerBuffer;
                ssize_t n;
                bool hasHeader = false;

                while (!hasHeader && (n = read(fd, buffer, sizeof(buffer))) > 0)
                {
                    headerBuffer.append(buffer, n);
                    size_t crfl = headerBuffer.find("\r\n\r\n");
                    if (crfl != std::string::npos)
                    {
                        std::string cgiHeaders = headerBuffer.substr(0, crfl + 4);
                        client->bodyOffSet = crfl + 4;
                        hasHeader = true;
                    }
                }
                // HANDLE CGI NO HEADER ERROR;
                if (!hasHeader) {};

                response.setFileContentLength(client->writePath, client->bodyOffSet);

            }
            else if (content_type.find("multipart/form-data") != std::string::npos)
            {
                std::string body = request.getBody(client->getBuffer());
                size_t pos = content_type.find("boundary=");
                if (pos != std::string::npos)
                {
                    std::string boundary = "--" + content_type.substr(pos + 9);
                    size_t start = 0;
                    std::string response_body;
                    // *** Removed mkdir call: make sure "www/uploads" directory exists manually ***

                    while ((start = body.find(boundary, start)) != std::string::npos)
                    {
                        size_t header_end = body.find("\r\n\r\n", start);
                        if (header_end == std::string::npos)
                            break;

                        std::string headers = body.substr(start, header_end - start);
                        size_t filename_pos = headers.find("filename=\"");

                        if (filename_pos != std::string::npos)
                        {
                            size_t start_filename = filename_pos + 10;
                            size_t end_filename = headers.find("\"", start_filename);
                            std::string filename = headers.substr(start_filename, end_filename - start_filename);

                            if (!filename.empty())
                            {
                                size_t content_start = header_end + 4;
                                size_t next_boundary = body.find(boundary, content_start);
                                if (next_boundary == std::string::npos)
                                    break;

                                size_t content_end = next_boundary;
                                // Remove trailing CRLF
                                if (body[content_end - 2] == '\r' && body[content_end - 1] == '\n')
                                {
                                    content_end -= 2;
                                }

                                std::string filepath = "www/uploads/" + filename;
                                std::ofstream out(filepath.c_str(), std::ios::binary);
                                if (out.is_open())
                                {
                                    out.write(&body[content_start], content_end - content_start);
                                    out.close();
                                    response_body += "<p>Uploaded: " + filename + "</p>\n";
                                }
                                else
                                {
                                    response_body += "<p>Failed to save: " + filename + "</p>\n";
                                }
                            }
                        }

                        // Move to next part
                        start = body.find(boundary, start + boundary.length());
                    }

                    response.setStatus(201);
                    response.setBody("<h1>Upload Result</h1>\n" + response_body);
                }
                else
                {
                    response.setStatus(400);
                    response.setBody("<h1>Bad Request: No boundary found</h1>");
                }
            }
            else
            {
                std::string body = request.getBody(client->getBuffer());
                std::ofstream out(path.c_str(), std::ios::binary);
                if (out.is_open())
                {
                    out.write(body.data(), body.size());
                    out.close();
                    response.setStatus(201);
                    response.setBody("<h1>File uploaded successfully</h1>");
                }
                else
                {
                    response.setStatus(500);
                    response.setBody("<h1>Failed to save file</h1>");
                }
            }

            response.setContentType("text/html");
        }

        if (method == "DELETE")
        {
            std::string path = "www" + uri;
            if (remove(path.c_str()) == 0)
            {
                response.setStatus(200);
                response.setBody("<h1>File deleted</h1>");
            }
            else
            {
                response.setDefaultErrorBody(404);
            }
            response.setContentType("text/html");
        }

        response.build();

        client->state = RESPONSE;
    }

    if (client->state == RESPONSE)
    {
        switchEvents(client->client_fd, "POLLOUT");
        handleClientWrite(client);
    }
}

void Server::closeConnection(int fd)
{
    close(fd);

    for (size_t i = 0; i < _fds.size(); ++i)
    {
        if (_fds[i].fd == fd)
        {
            _fds.erase(_fds.begin() + i);
            break;
        }
    }

    this->removeClientByFd(fd);
}

void Server::runCgi(Client *client, const std::string &scriptPath, const std::string &interpreter, const std::string &tmp_file)
{
    int pipefd[2];

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        return ;
    }

    pid_t pid = fork();
    if (pid < 0)
    {
        perror("pid");
        return ;
    }

    if (pid == 0)
    {
        close(pipefd[0]);

        int fd = open(tmp_file.c_str(), O_RDONLY);

        if (fd < 0) { perror("open tmp_file"); exit(1); }

        dup2(fd, STDIN_FILENO);
        close(fd);

        dup2(pipefd[1], STDOUT_FILENO);
        dup2(pipefd[1], STDERR_FILENO);
        close(pipefd[1]);

        if (interpreter.empty())
        {
            struct stat st;
            if (stat(tmp_file.c_str(), &st) == 0)
            {
                std::stringstream ss;
                ss << st.st_size;
                setenv("CONTENT_LENGTH", ss.str().c_str(), 1);
            }
            else
                perror("stat tmp_file");
              
            
            setenv("SERVER_PROTOCOL", "HTTP/1.1", 1);
            setenv("REQUEST_METHOD", "POST", 1);
            setenv("CONTENT_TYPE", "application/x-www-form-urlencoded", 1);
            setenv("SCRIPT_NAME", "", 1);
            setenv("PATH_INFO", "/example/path", 1);
            execlp(scriptPath.c_str(), scriptPath.c_str(), NULL);
        }
        else
            execlp(interpreter.c_str(), interpreter.c_str(), scriptPath.c_str(), NULL);

        // If execlp fails
        perror("execlp");
        exit(1);
    }
    else
    {
        close(pipefd[1]); 

        fcntl(pipefd[0], F_SETFL, O_NONBLOCK);

        struct pollfd pfd;
        pfd.fd = pipefd[0];
        pfd.events = POLLIN;
        pfd.revents = 0;

        this->_fds.push_back(pfd);
        this->_writeJobs[pipefd[0]] = client->client_fd;
        client->writingFile =  true;
        client->writePath = "tmp_response.dat";
        int status;
        waitpid(pid, &status, 0);
    }
}

bool Server::_isDirectory(const std::string &path)
{
    struct stat info;
    if (stat(path.c_str(), &info) != 0)
        return false;
    return S_ISDIR(info.st_mode);
}

void Server::fileStream(Client *client)
{
    size_t CHUNK_SIZE = 4 * 1024 * 1024;
    Response &res = client->getResponse();
    if (client->write_fd == -1) {
        client->write_fd = open(client->writePath.c_str(), O_RDONLY);
        if (client->write_fd == -1) {
            perror("open");
            return;
        }
        if (client->bodyOffSet > 0) {
            if (lseek(client->write_fd, client->bodyOffSet, SEEK_SET) == -1) {
                perror("lseek");
                close(client->write_fd);
                return;
            }
        }
    }
    std::vector<char> buffer(CHUNK_SIZE);
    ssize_t bytesReader = read(client->write_fd, &buffer[0], sizeof(buffer));
    if (bytesReader)  {
        ssize_t byteSend = send(client->client_fd, &buffer[0], bytesReader, 0);
        if (byteSend) { res._indexByteSend += byteSend; }
    } else {
        close(client->write_fd);
        client->write_fd = -1;
        return;
    }
}

bool Server::_isFile(const std::string &path)
{
    struct stat info;
    if (stat(path.c_str(), &info) != 0)
        return false;
    return S_ISREG(info.st_mode);
}
