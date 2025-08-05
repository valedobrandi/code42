/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:26:56 by bde-albu          #+#    #+#             */
/*   Updated: 2025/08/05 15:10:24 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_CLASS_HPP
# define SERVER_CLASS_HPP

# include "webserv.hpp"
# include <vector>
# include <set>

class Server
{
  private:

	std::vector<struct pollfd> _fds;
	std::set<int> _sockets_listen_fds;

  public:
	Server(void);
	Server(const Server &other);
	Server &operator=(const Server &other);
	~Server(void);

	Server(int *port);
	void poll_connections(std::vector<Connection> &connections);
};

#endif