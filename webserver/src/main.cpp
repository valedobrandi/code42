/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:26:13 by bde-albu          #+#    #+#             */
/*   Updated: 2025/08/05 12:43:42 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "webserv.hpp"
#include "Server.hpp"

int main( void ) {

	std::vector<Connection> connections;

	int connection_ports[] = { 8000, 8080, 3030 };

	Server connect(connection_ports);


	connect.poll_connections(connections);

}

/* int main(void)
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_addr;

    std::memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    bind(server_fd, (sockaddr *)&server_addr, sizeof(server_addr));

    listen(server_fd, 1);

    std::cout << "Server is listening on port 8080" << std::endl;

    fcntl(server_fd, F_SETFL, O_NONBLOCK);

    std::vector<pollfd> fds;
	struct pollfd pfd;
    pfd.fd = server_fd;
    pfd.events = POLLIN;
	pfd.revents = 0;
    fds.push_back(pfd);

	int client_fd;;
    while (true) {
        int ready = poll(fds.data(), fds.size(), 600);
        if (ready <= 0) continue;
        for (size_t i = 0; i < fds.size(); i++) {
            if (fds[i].revents && POLLIN) {
                if (fds[i].fd == server_fd) {

                    struct sockaddr_in client_addr;
					socklen_t client_len = sizeof(client_addr);
					client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);

                    if ( client_fd == -1 ) break;

                    fcntl(server_fd, F_SETFL, O_NONBLOCK);

					struct pollfd pfd;
					pfd.fd = client_fd;
					pfd.events = POLLIN;
					pfd.revents = 0;
					fds.push_back(pfd);

                    std::cout << "Connected:" << inet_ntoa(client_addr.sin_addr) << std::endl;

                } else {
                    char buffer[1024];
                    std::memset(buffer, 0, sizeof(buffer));
                    int bytes_reader = recv(fds[i].fd, buffer, sizeof(buffer) - 1, 0);
                    if (bytes_reader <= 0) {
                        close(fds[i].fd);
                        fds.erase(fds.begin() + i);
                        --i;
                    } else {
                        const char *reply = "Hello Word!\n";
                        send(client_fd, reply, strlen(reply), 0);
                    }
                }
            }
        }

    }

    return 0;
} */