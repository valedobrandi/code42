/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:52:06 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/08 10:52:07 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( void ) {};

void Zombie::setName( std::string name ) {
	this->name = name;
	return;
}

void    Zombie::announce( void ) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}


Zombie::~Zombie( void ) {
    std::cout << this->name << ": destroyed" << std::endl;
    return ;
}