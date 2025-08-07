/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:09:02 by bde-albu          #+#    #+#             */
/*   Updated: 2025/08/04 11:09:04 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>

int file_conf(const std::string& filename) {
    size_t lastDot = filename.find_last_of('.');
    if ( !std::strncmp(&filename[lastDot], ".conf", 4) )
		return 0;
	return 1;
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		std::fstream read_file(av[1], std::ios::in);
        if (!read_file.is_open() || file_conf(av[1])) {
            std::cerr << "Failed to open." << std::endl;
            return 1;
        }
	}
}