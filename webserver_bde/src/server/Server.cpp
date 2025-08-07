/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:05:52 by bde-albu          #+#    #+#             */
/*   Updated: 2025/08/07 12:15:51 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include <arpa/inet.h>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <poll.h>
#include <unistd.h>
#include <vector>

Server::Server(void)
{
}

Server::Server(const Server & /* other */)
{
}

Server &Server::operator=(const Server & /* other */)
{
	return (*this);
}

Server::~Server(void)
{
}

Server::Server(int *ports)
{
	int			server_fd;
	sockaddr_in	server_addr;

	if (ports == NULL)
		return ;
	for (size_t i = 0; i < 3; i++)
	{
		server_fd = socket(AF_INET, SOCK_STREAM, 0);
		fcntl(server_fd, F_SETFL, O_NONBLOCK);
		std::memset(&server_addr, 0, sizeof(server_addr));
		server_addr.sin_family = AF_INET;
		server_addr.sin_addr.s_addr = INADDR_ANY;
		server_addr.sin_port = htons(ports[i]);
		if (bind(server_fd, (sockaddr *)&server_addr, sizeof(server_addr)) < 0)
		{
			std::cerr << "Bind failed on port " << ports[i] << std::endl;
			continue ;
		}
		listen(server_fd, 50);
		this->_addQueve(server_fd);
		this->_sockets_listen_fds.insert(server_fd);
	}
}

void Server::poll_connections(std::map<int, Connection> &connections)
{
	int		ready;
	int		fd;
	char	buffer[1024];
	int		reader;
	size_t	headerEnd;

	while (true)
	{
		ready = poll(this->_fds.data(), this->_fds.size(), 600);
		if (ready <= 0)
			continue ;
		for (size_t i = 0; i < this->_fds.size(); i++)
		{
			fd = this->_fds[i].fd;
			if (this->_fds[i].revents & POLLIN)
			{
				if (this->_sockets_listen_fds.count(fd))
				{
					if (this->_acceptClient(fd, connections))
						continue ;
				}
				else
				{
					std::memset(buffer, 0, sizeof(buffer));
					reader = recv(fd, buffer, sizeof(buffer) - 1, 0);
					if (reader > 0)
					{
						connections[fd].buffer.append(buffer, reader);
						headerEnd = connections[fd].buffer.find("\r\n\r\n");
						if (connections[fd].state == REQUEST)
						{
							if (headerEnd != std::string::npos)
								this->_receiver(connections, fd);
							if (connections[fd].body)
								this->_getBody(connections, fd, headerEnd);
							if (reader <= 0 && connections[fd].state == REQUEST)
								this->_clearClient(connections, &i, fd);
						}
					}
				}
				if (connections[fd].state == RESPONSE)
				{
					send(this->_fds[i].fd, 0, 0, 0);
					connections[fd].state = DONE;
				}
				if (connections[fd].state == DONE)
					this->_clearClient(connections, &i, fd);
			}
		}
	}
}

void Server::_addQueve(int server_fd)
{
	struct pollfd	pfd;

	pfd.fd = server_fd;
	pfd.events = POLLIN;
	pfd.revents = 0;
	this->_fds.push_back(pfd);
}

int Server::_acceptClient(int fd, std::map<int, Connection> &connections)
{
	Connection			conn;
	socklen_t			client_len;
	struct sockaddr_in	client_addr;
	int					client_fd;

	client_len = sizeof(client_addr);
	client_fd = accept(fd, (struct sockaddr *)&client_addr, &client_len);
	if (client_fd == -1)
		return (1);
	fcntl(client_fd, F_SETFL, O_NONBLOCK);
	this->_addQueve(client_fd);
	conn.fd = client_fd;
	conn.contentLength = 0;
	conn.buffer = "";
	conn.state = REQUEST;
	connections[client_fd] = conn;
	std::cout << "Connected:" << inet_ntoa(client_addr.sin_addr) << std::endl;
	return (0);
}

void Server::_clearClient(std::map<int, Connection> &connections, size_t *i,
	int &fd)
{
	close(this->_fds[*i].fd);
	this->_fds.erase(this->_fds.begin() + *i);
	connections.erase(fd);
	--i;
}

void Server::_getBody(std::map<int, Connection> &connections, int fd,
	size_t headerEnd)
{
	size_t	bodyLength;

	bodyLength = headerEnd + 4 + connections[fd].contentLength;
	if (connections[fd].buffer.size() >= bodyLength)
		connections[fd].state = RESPONSE;
}

void Server::_receiver(std::map<int, Connection> &connections, int fd)
{
	size_t	index;
	size_t	eof;

	if (connections[fd].buffer.find("POST") != std::string::npos
		&& !connections[fd].body)
	{
		index = connections[fd].buffer.find("Content-Length:");
		if (index != std::string::npos)
		{
			index += std::string("Content-Length:").length();
			eof = connections[fd].buffer.find("\r\n", index);
			std::string getBodyLength = connections[fd].buffer.substr(index, eof
					- index);
			getBodyLength.erase(0, getBodyLength.find_first_not_of(" "));
			connections[fd].body = true;
			connections[fd].contentLength = atoi(getBodyLength.c_str());
		}
	}
	else
		connections[fd].state = RESPONSE;
}
