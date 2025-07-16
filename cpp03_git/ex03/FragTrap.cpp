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

    std::cout << this->_type << " " << this->_name << " was created" << std::endl;

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
	std::cout << "FragTrap "  << this->get_name() << " was destroyed" << std::endl;
    return;
}

void FragTrap::highFivesGuys() {
	std::cout << this->_type << " " << this->get_name() << " wants a high five.\n";
}

std::string FragTrap::get_name() const
{
	return this->_name;
}