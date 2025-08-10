/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                   	    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitran<thitran@student.42nice.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:26:13 by thitran           #+#    #+#             */
/*   Updated: 2025/08/04 13:52:34 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Config.hpp"
#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <fcntl.h>  // open
#include <unistd.h> // read, close
#include <cerrno>
#include <cstring> // strerror

Config::Config() {}

Config::~Config() {}

const std::vector<ServerConfig> &Config::getServers() const
{
    for (size_t i = 0; i < this->_servers.size(); ++i)
        this->_validate(this->_servers[i]);
    return _servers;
}

std::vector<int> Config::getPorts() const
{
    std::vector<int> ports;
    for (size_t i = 0; i < _servers.size(); ++i)
    {
        ports.push_back(_servers[i].port);
    }
    return ports;
}

std::string trim(const std::string &line)
{
    size_t start = line.find_first_not_of(" \t\r\n");
    size_t end = line.find_last_not_of(" \t\r\n");
    if (start == std::string::npos || end == std::string::npos)
        return "";
    return line.substr(start, end - start + 1);
}

void Config::_validate(const ServerConfig &config) const
{
    if (config.port < 0)
        throw std::runtime_error("Error: listen directive");
    if (trim(config.root) == "")
        throw std::runtime_error("Error: root directive");
}

std::vector<std::string> tokenize(const std::string &line)
{
    std::vector<std::string> tokens;
    std::string token;
    for (size_t i = 0; i < line.length(); ++i)
    {
        if (isspace(line[i]) || line[i] == ';')
        {
            if (!token.empty())
            {
                tokens.push_back(token);
                token.clear();
            }
        }
        else
        {
            token += line[i];
        }
    }
    if (!token.empty())
        tokens.push_back(token);
    return tokens;
}

void getMethods(std::vector<std::string> &tokens, LocationConfig &t)
{
    for (size_t it = 1; it < tokens.size(); ++it)
        t.allowed_methods.push_back(tokens[it]);
}

std::string readFile(const std::string &filename)
{
    int fd = open(filename.c_str(), O_RDONLY);
    if (fd < 0)
    {
        std::cerr << "Failed to open config file: " << strerror(errno) << std::endl;
        return "";
    }

    char buffer[4096];
    ssize_t bytesRead;
    std::string content;

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0)
    {
        content.append(buffer, bytesRead);
    }

    if (bytesRead < 0)
    {
        std::cerr << "Failed to read config file: " << strerror(errno) << std::endl;
        close(fd);
        return "";
    }

    close(fd);
}

bool Config::parseFile(const std::string &filename)
{
   
    std::string content = readFile(filename);

    if (content == "") return false;


    std::istringstream stream(content);
    std::string line;
    ServerConfig current;
    LocationConfig location;
    bool inside_server = false;
    bool inside_location = false;

    while (std::getline(stream, line))
    {
        line = trim(line);

        if (line.empty() || line[0] == '#')
            continue;

        if (line.find("server") == 0 && line.find("{") != std::string::npos)
        {
            inside_server = true;
            current = ServerConfig();
            continue;
        }

        if (inside_server)
        {
            if (line == "}")
            {
                _servers.push_back(current);
                inside_server = false;
                continue;
            }

            std::vector<std::string> tokens = tokenize(line);
            if (tokens.size() >= 2 && !inside_location)
            {
                if (tokens[0] == "listen")
                    current.port = std::atoi(tokens[1].c_str());
                else if (tokens[0] == "server_name")
                    current.server_name = tokens[1];
                else if (tokens[0] == "root")
                    current.root = tokens[1];
            }

            if (line.find("location") == 0 && line.find("{") != std::string::npos)
            {
                inside_location = true;
                location = LocationConfig();
            }

            if (inside_location)
            {
                if (line == "}")
                {
                    this->_servers.end()->locations.push_back(location);
                    inside_location = false;
                    continue;
                }

                if (tokens.size() >= 2)
                {
                    if (tokens[0] == "location")
                        location.path = tokens[1];
                    else if (tokens[0] == "root")
                        location.root = tokens[1];
                    else if (tokens[0] == "cgi_pass")
                        location.cgi_pass = tokens[1];
                    else if (tokens[0] == "allow_methods")
                        getMethods(tokens, location);
                    else if (tokens[0] == "index")
                        location.index = tokens[1];
                    else if (tokens[0] == "upload_store")
                        location.index = tokens[1];
                    else if (tokens[0] == "upload_store" && tokens[1] == "on")
                        location.autoIndex = true;
                    else if (tokens[0] == "client_max_body_size")
                        location.max_body = std::atoi(tokens[1].c_str());
                    else if (tokens[0] == "error_page")
                    {
                        location.errorPageCode = std::atoi(tokens[1].c_str()); 
                        location.errorPagePath = tokens[2];  
                    }
                    else if (tokens[0] == "return")
                    {
                        location.redirectCode = std::atoi(tokens[1].c_str()); 
                        location.redirectPath = tokens[2];  
                    }
                }
            }
        }
    }

    return true;
}