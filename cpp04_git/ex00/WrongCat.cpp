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

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    this->type = "WrongCat";
    return;
}

WrongCat::WrongCat(const WrongCat &other)
    : WrongAnimal()
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    this->type = other.type;
    return;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        WrongAnimal::operator=(rhs);
        this->type = rhs.type;
    }
    return *this;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called" << std::endl;
    return;
}

void WrongCat::makeSound( void ) const
{
    std::cout << "WrongCat SOUND: MIAUMIAUMIAU" << std::endl;
    return ;
}