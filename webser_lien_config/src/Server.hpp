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

#include "Client.hpp"
#include "Config.hpp"
#include "Connect.hpp"

typedef std::map<int, Connect *>::iterator ConnectIt;

class Server
{
public:
    Server();
    ~Server();

    void run();
    bool setup(Config &config);
    Client *findByClientFd(const int client_fd);
    bool removeClientByFd(const int client_fd);
    LocationConfig* getServerConfig(Client *);
    void switchEvents(int client_fd, std::string type);
    void handleClientWrite(Client *client);
    std::string vectorToString(std::vector<char>);


private:
    std::set<int> _sockets;
    std::vector<struct pollfd> _fds;
    std::vector<ServerConfig *> _connects;
    std::map<int , std::vector<LocationConfig *> > _locations;
    std::map<int, Client *> _clients;

    int createSocket(int);
    void acceptNewConnection(int);
    void closeClient(int client_fd);
    void handleClientData(Client *);
    bool _isAllowedMethod(std::vector<std::string>, std::string);
    std::vector<char>  runCgi(const std::string &scriptPath, const std::string &interpreter, /* int client_fd,  */const std::string &post_body);

    bool _isDirectory(const std::string &path);
    bool _isFile(const std::string &path);

};

#endif
