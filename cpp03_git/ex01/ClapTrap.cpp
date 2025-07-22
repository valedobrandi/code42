#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _hitPoints(10), _energyPoints(10), _attackDamage(0),
	_type("ClapTrap")
{
	std::cout << this->_type << " constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name),
	_hitPoints(other._hitPoints), _energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage), _type("ClapTrap")
{
	std::cout << this->_type << " copy constructor called\n";
	return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << this->_type << " assignment operator called\n";
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
		_type = "ClapTrap";
	}
	return (*this);
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0), _type("ClapTrap")
{
	std::cout << this->_type << " " << this->getName() << " was created" << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->getName() << " was destroyed" << std::endl;
	return ;
}

void ClapTrap::attack(const std::string &target)
{
	if (!this->status())
		return ;
	this->_energyPoints--;
	std::cout << this->_type << " " << this->getName() << " attacks " << target << ", causing "
		<< this->_attackDamage << " points of damage!" << std::endl;
	return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_type << " " << this->getName() << " is dead!" << std::endl;
		return ;
	}
	std::cout << this->_type << " " << this->getName() << " take " << amount << " points of damage!" << std::endl;
	this->_hitPoints -= amount;
	return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->status())
		return ;
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << this->_type << " " << this->getName() << " repair " << amount << " points of damage!" << std::endl;
	return ;
}

bool ClapTrap::status(void)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_type << " " << this->getName() << " is dead!" << std::endl;
		return (false);
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_type << " " << this->getName() << " is exhausted!" << std::endl;
		return (false);
	}
	return (true);
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

int ClapTrap::getHitPoints() const
{
	return (this->_hitPoints);
}

int ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

int ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

int ClapTrap::getEnergyPoints( void ) const
{
     return this->_energyPoints;
}