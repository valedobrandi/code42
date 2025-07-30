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

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
    return;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    this->type = other.type;
    return;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
    return;
}

void WrongAnimal::makeSound( void ) const 
{
    std::cout << "WrongAnimal SOUND:" << std::endl;
    return ;
}

std::string WrongAnimal::getType( void ) const 
{
    return this->type;
}