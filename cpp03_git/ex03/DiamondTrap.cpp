#include "DiamondTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap( void )
	: ClapTrap(), FragTrap(), ScavTrap()
{
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints =  ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_hitPoints;
	this->_type = "DiamondTrap";
	this->_name = "DEF00";

    std::cout << this->_type << " constructor called" << std::endl;

    return;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap( name + "_clap_name"), FragTrap(), ScavTrap()
{
	this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints =  ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
	this->_type = "DiamondTrap";
	this->_name = name;

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
	if (this != &other) {
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		this->_name = other._name;
		this->_type = other._type;
	}
    std::cout << this->_type << " assignment operator called\n";
    return *this;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap "  << this->get_name() << " was destroyed" << std::endl;
    return;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
	return ;
}

std::string DiamondTrap::get_name() const
{
	return this->_name;
}

void DiamondTrap::whoAmi( void ) {
	std::cout << this->get_name() << std::endl;
	std::cout << ClapTrap::_name << std::endl;
	return ;
}