/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:26:56 by bde-albu          #+#    #+#             */
/*   Updated: 2025/08/07 12:15:13 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_CLASS_HPP
# define SERVER_CLASS_HPP

# include "webserv.hpp"
# include <map>
# include <vector>
# include <set>

class Server
{
  private:

	std::vector<struct pollfd> _fds;
	std::set<int> _sockets_listen_fds;

	void _addQueve( int server_fd );
	int _acceptClient( int fd, std::map<int, Connection> &connections );
	void _clearClient(std::map<int, Connection> &connections, size_t* i, int& fd);
	void _getBody(std::map<int, Connection> &connections, int fd, size_t headerEnd);
	void _receiver(std::map<int, Connection> &connections, int fd);

  public:

	Server(void);
	Server(const Server &other);
	Server &operator=(const Server &other);
	~Server(void);

	Server(int *port);
	void poll_connections(std::map<int, Connection>&);

};

#endif