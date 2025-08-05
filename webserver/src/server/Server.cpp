/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:05:52 by bde-albu          #+#    #+#             */
/*   Updated: 2025/08/05 15:19:52 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include <arpa/inet.h>
#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <poll.h>
#include <unistd.h>
#include <vector>

Server::Server(void) {}

Server::Server(const Server &/* other */) {}

Server &Server::operator=(const Server &/* other */)
{
	return *this;
}

Server::~Server(void) {}

Server::Server(int *ports)
{
	int				server_fd;
	sockaddr_in		server_addr;
	struct pollfd	pfd;

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
		pfd.fd = server_fd;
		pfd.events = POLLIN;
		pfd.revents = 0;
		this->_fds.push_back(pfd);
		this->_sockets_listen_fds.insert(server_fd);
	}
}

void Server::poll_connections(std::vector<Connection> &/* connections */)
{
	int					client_fd;
	struct sockaddr_in	client_addr;
	socklen_t			client_len;
	struct pollfd		pfd;
	int					ready;

	while (true)
	{
		ready = poll(this->_fds.data(), this->_fds.size(), 600);
		if (ready <= 0)
			continue ;
		for (size_t i = 0; i < this->_fds.size(); i++)
		{
			if (this->_fds[i].revents & POLLIN)
			{
				int fd = this->_fds[i].fd;
				if (this->_sockets_listen_fds.count(fd))
				{
					client_len = sizeof(client_addr);
					client_fd = accept(this->_fds[i].fd, (struct sockaddr *)&client_addr, &client_len);
					if (client_fd == -1)
						continue ;
					fcntl(client_fd, F_SETFL, O_NONBLOCK);
					pfd.fd = client_fd;
					pfd.events = POLLIN;
					pfd.revents = 0;
					this->_fds.push_back(pfd);
					std::cout << "Connected:" << inet_ntoa(client_addr.sin_addr) << std::endl;
				} else {
                    char buffer[1024];
                    std::memset(buffer, 0, sizeof(buffer));
                    int bytes_reader = recv(this->_fds[i].fd, buffer, sizeof(buffer) - 1, 0);
                    if (bytes_reader <= 0) {
                        close(this->_fds[i].fd);
                        this->_fds.erase(this->_fds.begin() + i);
                        --i;
                    } else {
                        const char *reply = "Hello World!\n";
                        send(this->_fds[i].fd, reply, strlen(reply), 0);
                    }
                }
			}
		}
	}
}
