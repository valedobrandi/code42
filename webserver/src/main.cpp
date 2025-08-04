/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:26:13 by bde-albu          #+#    #+#             */
/*   Updated: 2025/08/04 15:28:00 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <poll.h>
#include <vector>

int main(void)
{
	std::vector <pollfd> fds;
	pollfd listener_fd;


	// BERNARDO
	int server_fd = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in server_addr;

	std::memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(8080);

	bind(server_fd, (sockaddr*)&server_addr, sizeof(server_addr));

	listen(server_fd, 1);

	std::cout << "Server is listening on port 8080" << std::endl;

	listener_fd.fd = server_fd;
	listener_fd.events = POLLIN;
	fds.push_back(listener_fd);

	while (1) {
		
	}

	sockaddr_in client_addr;
	socklen_t client_len = sizeof(client_addr);
	int client_fd = accept(server_fd, (sockaddr*)&client_addr, &client_len);

	std::cout << "Connected:" << inet_ntoa(client_addr.sin_addr) << std::endl;

	// LIEN
	char buffer[1024];
	std::memset(buffer, 0, sizeof(buffer));
	recv(client_fd, buffer, sizeof(buffer) - 1, 0);


	const char* reply = "Hello Word!\n";
	send(client_fd, reply, strlen(reply), 0);

	close(client_fd);
	close(server_fd);

	return 0;
}