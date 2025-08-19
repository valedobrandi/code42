/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                   	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitran<thitran@student.42nice.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:26:13 by thitran           #+#    #+#             */
/*   Updated: 2025/08/04 13:52:34 by thitran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Request.hpp"
#include <sstream>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <iomanip>

class Connect;

Request::Request()
    : _bodyIndex(0),
      _bodyEndIndex(0),
      hasBody(false),
      hasHeader(false),
      _maxBodySize(0),
      _chunkSizeToWrite(0),
      _totalBytesRead(0) {}

Request::~Request() {}

bool Request::parseHeader(std::vector<char> &buffer)
{
    std::vector<char>::iterator header_end = std::search(
        buffer.begin(), buffer.end(), "\r\n\r\n", "\r\n\r\n" + 4);
    if (header_end == buffer.end())
        return false;

    std::string headerPart(buffer.begin(), header_end);

    std::istringstream stream(headerPart);
    std::string line;

    // First line: Request Line
    if (!std::getline(stream, line))
        return false;
    parseRequestLine(line);

    // Other lines: Headers
    std::string headers;
    while (std::getline(stream, line))
    {
        if (!line.empty() && line[line.size() - 1] == '\r')
            line.erase(line.size() - 1);
        headers += line;
        headers += "\n";
    }

    parseHeaders(headers);

    // Extract host (without port)
    this->_host = getHeader("Host");
    size_t index = this->_host.find(":");

    if (index != std::string::npos)
        this->_hostname = this->_host.substr(0, index);
    else
        this->_hostname = this->_host;

    this->_bodyIndex = std::distance(buffer.begin(), header_end) + 4;
    std::cout << "_bodyStartIndex: " << _bodyIndex << std::endl;
    _bodyEndIndex = this->_bodyIndex;

    hasHeader = true;

    if (!getHeader("Content-Length").empty() || !getHeader("Transfer-Encoding").empty())
    {
        this->hasBody = true;
    }

    return true;
}

void Request::parseRequestLine(const std::string &line)
{
    std::istringstream ss(line);
    ss >> _method >> _uri >> _version;
}

void Request::parseHeaders(const std::string &headerSection)
{
    std::istringstream stream(headerSection);
    std::string line;
    while (std::getline(stream, line))
    {
        std::string::size_type pos = line.find(":");
        if (pos == std::string::npos)
            continue;

        std::string key = trim(line.substr(0, pos));
        std::string value = trim(line.substr(pos + 1));
        _headers[key] = value;
    }
}

int Request::parseBody(std::vector<char> &buffer, size_t maxBodySize)
{
    std::string contentLength = getHeader("Content-Length");
    std::string transferEnconding = getHeader("Transfer-Encoding");

    if (!contentLength.empty())
    {
        std::istringstream ss(contentLength);
        size_t length;
        ss >> length;

        if (maxBodySize && length > maxBodySize)
            return 2;

        if (buffer.size() <= _bodyIndex)
            return 1;

        size_t availableBodyData = buffer.size() - _bodyIndex;
        if (availableBodyData >= length)
        {
            return 0;
        }
    }
    else if (transferEnconding == "chunked")
    {
        std::string parseChunck = "\r\n";

        if (maxBodySize && this->_maxBodySize > maxBodySize)
            return 2;

        while (true)
        {
            std::vector<char>::iterator it = std::search(
                buffer.begin() + _bodyIndex, buffer.end(), parseChunck.begin(), parseChunck.end());

            if (it == buffer.end()) return 1;

            std::string getChunkSize(buffer.begin() + _bodyIndex, it);

            std::cout << "getChunkSize: " << getChunkSize << std::endl;

            size_t chunckSize = strtoul(getChunkSize.c_str(), NULL, 16);


            if (chunckSize == 0)
            {
                if (buffer.size() >= _bodyIndex + 2)
                    _bodyIndex += 2;
                std::cout << "BytesToWrite: " << _maxBodySize << std::endl;
                return 0;
            }

            if (buffer.size() < chunckSize + 4) return 1;

            _bodyIndex = (it - buffer.begin()) + 2;

            std::ofstream out("/tmp/cgi_input", std::ios::binary | std::ios::app);
            out.write(buffer.data() + _bodyIndex, chunckSize);
            _maxBodySize += chunckSize;

            _bodyIndex += chunckSize + 2;
        }
    }

    return 1;
}

std::string Request::trim(const std::string &s) const
{
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    if (start == std::string::npos || end == std::string::npos)
        return "";
    return s.substr(start, end - start + 1);
}

std::string Request::getMethod() const
{
    return _method;
}

std::string Request::getHost() const
{
    return _host;
}

std::string Request::getURI() const
{
    return _uri;
}

std::string Request::getVersion() const
{
    return _version;
}

std::string Request::getHeader(const std::string &key) const
{
    std::map<std::string, std::string>::const_iterator it = _headers.find(key);
    if (it != _headers.end())
        return it->second;
    return "";
}

std::string Request::getBody(std::vector<char> buffer) const
{
    return std::string(buffer.begin() + _bodyIndex, buffer.end());
}

std::string Request::getHostname() const
{
    return _hostname;
}

bool Request::isComplete() const
{
    return _complete;
}
