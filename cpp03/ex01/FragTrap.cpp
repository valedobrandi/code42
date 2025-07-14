#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap( void ) : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;

    std::cout << "FragTrap constructor called" << std::endl;

    return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;

    std::cout << "FragTrap: " << this->_name << " was created" << std::endl;

    return;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called\n";
    return;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << _name << " wants a high five.\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    ClapTrap::operator=(other);
    std::cout << "FragTrap assignment operator called\n";
    return *this;
}

FragTrap::~FragTrap( void )
{
    std::cout << "FragTrap destructor called\n";
    return;
}