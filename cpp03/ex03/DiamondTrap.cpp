#include "DiamondTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap( void ) : FragTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
	_type = "DiamondTrap";

    std::cout << this->_type << " constructor called" << std::endl;

    return;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
	_type = "DiamondTrap";

    std::cout << this->_type << " " << this->_name << " was created" << std::endl;

    return;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap( other ), FragTrap( other ), ScavTrap( other )
{
    std::cout << this->_type << " copy constructor called\n";
    return;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	FragTrap::operator=(other);
    std::cout << this->_type << " assignment operator called\n";
    return *this;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap "  << this->_name << " was destroyed" << std::endl;
    return;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
	return ;
}