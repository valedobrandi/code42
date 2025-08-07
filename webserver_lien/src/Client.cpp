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

Client::Client() : _fd(-1), _requestReady(false) {}

Client::Client(int fd) : _fd(fd), _requestReady(false) {}

Client::~Client() {}

int Client::getFd() const {
    return _fd;
}

void Client::setFd(int fd) {
    _fd = fd;
}

std::string &Client::getBuffer() {
    return _buffer;
}

Request &Client::getRequest() {
    return _request;
}

Response &Client::getResponse() {
    return _response;
}

bool Client::parseRequest() {
    if (_request.parse(_buffer)) {
        _requestReady = true;
        return true;
    }
    return false;
}

bool Client::isRequestReady() const {
    return _requestReady;
}

void Client::reset() {
    _buffer.clear();
    _request = Request();
    _response = Response();
    _requestReady = false;
}
