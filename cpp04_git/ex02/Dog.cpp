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

#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

Dog::Dog(void) : Animal(), brain( new Brain )
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
    return;
}

Dog::Dog(const Dog &other) : Animal( other )
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = other.type;
    this->brain = new Brain( *other.brain );
    return;
}

Dog &Dog::operator=(const Dog& rhs)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        this->type = rhs.type;
        if (this->brain) delete this->brain;
        this->brain = new Brain( *rhs.brain );
    }
    return *this;
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
    return;
}

void Dog::makeSound( void ) const
{
    std::cout << "DOG SOUND: AUAUAUAUAU" << std::endl;
    return ;
}