/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:27:23 by bde-albu          #+#    #+#             */
/*   Updated: 2025/08/06 14:21:34 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HPP
# define WEBSERV_HPP

#include <string>

enum ConnectionState {
	WAIT,
	BODY,
	DONE,
};

struct Connection {
	int fd;
	int contentLength;
	std::string buffer;
	ConnectionState state;
};


#endif