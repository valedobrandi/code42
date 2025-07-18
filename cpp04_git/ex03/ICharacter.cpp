#include "ICharacter.hpp"
#include <iostream>

ICharacter::ICharacter(void) : _name(""), inventory({0})
{
    std::cout << "ICharacter default constructor called" << std::endl;
    return;
}

ICharacter::ICharacter(const ICharacter &other)
{
    std::cout << "ICharacter copy constructor called" << std::endl;
    return;
}

ICharacter &ICharacter::operator=(const ICharacter &rhs)
{
    std::cout << "ICharacter copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
    }
    return *this;
}

ICharacter::~ICharacter(void)
{
    std::cout << "ICharacter destructor called" << std::endl;
    return;
}

void ICharacter::ICharacter(std::string name)
    : _name(name), inventory({0})
{
    std::cout << "ICharacter " << this->_name << " constructor called" << std::endl;
    return;
}

std::string const &ICharacter::getName() const
{
    return this->_name;
}

void ICharacter::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++) if (this->inventory[i] == nullptr) break;
    if (i == 4) return;
    AMateria other = new AMateria(*m);
    this->inventory[index] = &other;
    index++;
    return ;
}
void ICharacter::unequip(int idx)
{
     if (this->inventory[idx]) delete this->inventory[idx];
     return ;
}
void ICharacter::use(int idx, ICharacter &target)
{
    if (this->inventory[idx])
    {
        (*this->inventory[idx]->use(target));
    }
    return ;
}