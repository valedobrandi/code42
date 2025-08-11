#include "Connect.hpp"
#include <iostream>
#include <algorithm>

Connect::Connect(int fd, std::vector<ServerConfig> data) : server_fd(fd), configs(data)
{
}

LocationConfig Connect::getLocationConfig(std::string host, std::string uri)
{
    LocationConfig conf;
    for (size_t it = 0; it < this->configs.size(); ++it) {
        if (configs[it].server_name == host) {
            for (size_t at = 0; at < configs[it].locations.size(); ++at) {
                if (configs[it].locations[at].path == uri)
                    conf = configs[it].locations[at];
            }
        }
    }
    return conf;
}

bool Connect::isAllowedMethod(std::vector<std::string> allowed_methods, std::string method)
{
    if (allowed_methods.empty() && method == "GET")
        return true;
    if (std::find(allowed_methods.begin(), allowed_methods.end(), method) == allowed_methods.end())
        return false;
    return true;
}

Connect::Connect() : server_fd(-1) {}

Connect::~Connect(void)
{
    for (std::map<int, Client *>::iterator it = clients.begin(); it != clients.end(); ++it)
    {
        delete it->second;
    }
}

std::ostream &operator<<(std::ostream &os, const Connect &conn)
{
    os << "[Connect] server_fd: " << conn.server_fd
       << ", clients: " << conn.clients.size();
    return os;
}
