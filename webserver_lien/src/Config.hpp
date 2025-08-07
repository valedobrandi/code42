/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                 	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thitran<thitran@student.42nice.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:26:13 by thitran           #+#    #+#             */
/*   Updated: 2025/08/04 13:52:34 by thitran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <map>
#include <vector>

struct ServerConfig {
    int port;
    std::string server_name;
    std::string root;
    std::map<int, std::string> error_pages;
};

class Config {
public:
    Config();
    ~Config();

    bool parseFile(const std::string &filename);
    const std::vector<ServerConfig> &getServers() const;
    std::vector<int> getPorts() const;  // Add this method

private:
    std::vector<ServerConfig> _servers;

    std::string trim(const std::string &line);
    std::vector<std::string> tokenize(const std::string &line);
};

#endif
