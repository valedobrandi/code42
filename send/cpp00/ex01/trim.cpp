/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 09:11:06 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/08 09:11:32 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string trim(const std::string &str)
{
	size_t	start;
	size_t	end;

	start = str.find_first_not_of(" \t\n\r\f\v");
	end = str.find_last_not_of(" \t\n\r\f\v");
	if (start == std::string::npos)
		return ("");
	return (str.substr(start, end - start + 1));
}
