/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                   	    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitran<thitran@student.42nice.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:26:13 by thitran           #+#    #+#             */
/*   Updated: 2025/08/04 13:52:34 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <sys/socket.h>

Client::Client(void) : buffer(8192), client_fd(-1), server_fd(-1), location(NULL), hasCGI(false)
{
}

Client::Client(const Client &other) : client_fd(other.client_fd), server_fd(other.server_fd), location(other.location), hasCGI(other.hasCGI)
{
}

Client::Client(int client_fd, int server_fd) :
    buffer(8192),
    client_fd(client_fd), 
    server_fd(server_fd), 
    location(NULL), 
    state(HEADER), 
    hasCGI(false), 
    _requestReady(false)
{
    this->_request = Request();
    this->_response = Response();
}

Client::~Client() {}

int Client::getFd() const
{
    return client_fd;
}

std::vector<char> &Client::getBuffer()
{
    return buffer;
}

Request &Client::getRequest()
{
    return _request;
}

Response &Client::getResponse()
{
    return _response;
}

bool Client::parseHeader()
{
    if (_request.parseHeader(buffer))
        return true;
    return false;
}

int Client::parseBody(size_t maxBodySize)
{
    return _request.parseBody(buffer, maxBodySize);
}

void Client::reset()
{
    buffer.clear();
    _request = Request();
    _response = Response();
    _requestReady = false;
}
void Client::receive()
{
    ssize_t bytesReader = recv(client_fd, buffer.data() + _request.byteEnd, buffer.size() - _request.byteEnd, 0);

    _request.byteEnd += bytesReader;

    size_t leftover = _request.byteEnd - _request.byteStart ;
    memmove(buffer.data(), buffer.data() + _request.byteStart , leftover);

    _request.byteStart = 0;
    _request.byteEnd = leftover;

}
std::ostream &operator<<(std::ostream &os, const Client &client)
{
    os << "[Client] client_fd: " << client.client_fd
       << ", server_fd: " << client.server_fd;
    return os;
}