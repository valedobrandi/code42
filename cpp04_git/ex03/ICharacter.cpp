#include "ICharacter.hpp"
#include <iostream>

ICharacter::ICharacter(void) : _name("")
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << "ICharacter default constructor called" << std::endl;
	return ;
}

ICharacter::ICharacter(const ICharacter &other)
{
	std::cout << "ICharacter copy constructor called" << std::endl;
	this->_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i];
	}
	return ;
}

ICharacter &ICharacter::operator=(const ICharacter& rhs)
{
	std::cout << "ICharacter copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
			if (rhs.inventory[i])
				this->inventory[i] = rhs.inventory[i];
		}
	}
	return (*this);
}

ICharacter::~ICharacter(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
		}

	}
	std::cout << "ICharacter destructor called" << std::endl;
	return ;
}

ICharacter::ICharacter(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << "ICharacter " << this->_name << " constructor called" << std::endl;
	return ;
}
