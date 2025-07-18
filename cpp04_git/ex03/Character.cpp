#include "Character.hpp"
#include "ICharacter.hpp"
#include <iostream>

Character::Character(void) : _name(""), inventory({0})
{
    std::cout << "Character default constructor called" << std::endl;
    return;
}

Character::Character(const Character &other)
{
    std::cout << "Character copy constructor called" << std::endl;
    return;
}

Character &Character::operator=(const Character &rhs)
{
    std::cout << "Character copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
    }
    return *this;
}

Character::~Character(void)
{
    std::cout << "Character destructor called" << std::endl;
    return;
}

void Character::Character(std::string name)
    : _name( name ), inventory( {0} )
{
    std::cout << "Character " << this->_name << " constructor called" << std::endl;
    return;
}
