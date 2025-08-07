/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                 	    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitran<thitran@student.42nice.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:26:13 by thitran           #+#    #+#             */
/*   Updated: 2025/08/04 13:52:34 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include "Request.hpp"
#include "Response.hpp"

class Client {
public:
    Client();
    Client(int fd);
    ~Client();

    int getFd() const;
    void setFd(int fd);
    std::string &getBuffer();
    Request &getRequest();
    Response &getResponse();

    bool parseRequest();      // returns true if request is complete
    bool isRequestReady() const;
    void reset();             // reset for next request

private:
    int _fd;
    std::string _buffer;
    Request _request;
    Response _response;
    bool _requestReady;
};

#endif

