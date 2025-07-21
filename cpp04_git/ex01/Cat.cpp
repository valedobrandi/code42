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

#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat(void) : Animal(), brain( new Brain )
{
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
    return;
}

Cat::Cat(const Cat &other)
    : Animal()
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = other.type;
    this->brain = new Brain( *other.brain );
    return;
}

Cat &Cat::operator=(const Cat &rhs)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        this->type = rhs.type;
        if (this->brain) delete this->brain;
        this->brain = new Brain( *rhs.brain );
    }
    return *this;
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
    return;
}

void Cat::makeSound( void ) const
{
    std::cout << "CAT SOUND: MIAUMIAUMIAU" << std::endl;
    return ;
}