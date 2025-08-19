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

enum ClientState
{
    REQUEST,
    BODY,
    RESPONSE,
    SEND,
    DONE
};

struct CgiResult {
    int statusCode;
    std::map<std::string, std::string> headers;
    std::string body;
    std::string contentType;
};

class Client
{
public:
    const int client_fd;
    const int server_fd;
    LocationConfig* location; 
    ClientState state;
    std::vector<char> output;
    bool hasCGI;
 
    Client(void);
    Client(const Client &other);
    Client(int client_fd, int server_fd);
    ~Client();

    int getFd() const;
    std::vector<char> &getBuffer();
    Request &getRequest();
    Response &getResponse();

   
    bool parseHeader();
    int parseBody(size_t maxBodySize);
    bool isRequestReady() const;

    void reset();

private:
    std::vector<char> _buffer;
    bool _requestReady;
    Request _request;
    Response _response;
};

std::ostream &operator<<(std::ostream &os, const Client &client);

#endif
