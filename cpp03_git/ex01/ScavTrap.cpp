#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap( void ) : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
	_type = "ScavTrap";

    std::cout << this->_type << " constructor called" << std::endl;

    return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
	_type = "ScavTrap";

    std::cout << this->_type << " " << this->_name << " was created" << std::endl;

    return;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << this->_type << " copy constructor called\n";
    return;
}

void ScavTrap::guardGate() {
	if (!this->status()) return;
    std::cout << this->_type << " " << _name << " is now in Gatekeeper mode.\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    ClapTrap::operator=(other);
    std::cout << this->_type << " assignment operator called\n";
    return *this;
}

ScavTrap::~ScavTrap( void )
{
    std::cout << "ScavTrap "  << this->_name << " was destroyed" << std::endl;
    return;
}

void ScavTrap::attack(const std::string &target)
{

    if (!this->status()) return;

    this->_energyPoints--;

    std::cout << this->_type << " " << this->_name << " shoot " << target << ", causing "
              << this->_attackDamage << " points of damage!" << std::endl;

    return;
}

std::string ScavTrap::getName() const
{
	return this->_name;
}