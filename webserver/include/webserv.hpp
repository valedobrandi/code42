/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:27:23 by bde-albu          #+#    #+#             */
/*   Updated: 2025/08/05 12:06:33 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HPP
# define WEBSERV_HPP

#include <string>

enum ConnectionState {
	HEADER,
	BODY,
	READY,
	DONE
};

struct Connection {
	int fd;
	std::string buffer;
	ConnectionState state;
	size_t body_size;
	std::string header;
	std::string body;
};


#endif