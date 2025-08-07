/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                 	    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitran<thitran@student.42nice.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:26:13 by thitran           #+#    #+#             */
/*   Updated: 2025/08/04 13:52:34 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include <vector>
#include <map>
#include <string>
#include <sys/poll.h>
#include <set>

#include "webserv.hpp"
#include "Client.hpp"
#include "Config.hpp"

class Server {
public:
    Server();
    ~Server();

    bool addPort(int port);
    bool setup();
    void run();

    void setConfig(const Config* config);

private:
    std::vector<int> _ports;
    std::vector<int> _sockets;
    std::map<int, Client> _clients;
    std::vector<struct pollfd> _pollfds;

	std::vector<struct pollfd> _fds;
	std::set<int> _sockets_listen_fds;
	std::map<int, Connection> connections;

    bool createSocket(int port);
    void acceptNewConnection(int server_fd);
    void handleClientData(int client_fd);
    void closeClient(int client_fd);
    void runCgi(const std::string& scriptPath, const std::string& interpreter, int client_fd);
};

#endif

