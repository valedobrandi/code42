/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                 	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitran<thitran@student.42nice.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:26:13 by thitran           #+#    #+#             */
/*   Updated: 2025/08/04 13:52:34 by thitran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <string>
#include <map>
#include "Config.hpp"
#include "Config.hpp"

struct Chunk
{
    size_t bytesReadFromChunk;
    size_t chunckSize;
    std::string hex;

    Chunk():
        bytesReadFromChunk(0),
        chunckSize(0),
        hex("") {}
};


class Request
{
public:

    Request();
    ~Request();

    Chunk chunk;
    size_t byteStart;
    size_t byteEnd;
    size_t _bodyEndIndex;
    bool hasBody;
    bool parseHeader(std::vector<char> &raw);
    int parseBody(std::vector<char> &buffer, size_t maxBodySize );
    std::string getMethod() const;
    std::string getHost() const;
    std::string getURI() const;
    std::string getVersion() const;
    std::string getHeader(const std::string &key) const;
    std::string getBody(std::vector<char> buffer) const;
    std::string getHostname() const;
    bool isComplete() const;

private:
    std::string _hostname; 
    std::string _method;
    std::string _uri;
    std::string _version;
    std::string _host;
    std::string _body;
    size_t _maxBodySize;

    size_t _chunkSizeToWrite;
    size_t _totalBytesRead;
    bool _complete;
    

    std::map<std::string, std::string> _headers;

    std::string trim(const std::string &s) const;
    void parseRequestLine(const std::string &line);
    void parseHeaders(const std::string &headerSection);
};

#endif
