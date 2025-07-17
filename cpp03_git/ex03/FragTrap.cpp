#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap( void ) : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
	_type = "FragTrap";

    std::cout << this->_type << " constructor called" << std::endl;

    return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
	_type = "FragTrap";

    std::cout << this->_type << " " << this->getName() << " was created" << std::endl;

    return;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << this->_type << " copy constructor called\n";
    return;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	ClapTrap::operator=(other);
    std::cout << this->_type << " assignment operator called\n";
    return *this;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap "  << this->getName() << " was destroyed" << std::endl;
    return;
}

void FragTrap::highFivesGuys() {
	std::cout << this->_type << " " << this->getName() << " wants a high five.\n";
}

std::string FragTrap::getName() const
{
	return this->_name;
}