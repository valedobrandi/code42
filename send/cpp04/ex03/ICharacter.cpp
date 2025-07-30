#include "ICharacter.hpp"
#include <iostream>

ICharacter::ICharacter(void) : _name("")
{
	//std::cout << "ICharacter default constructor called" << std::endl;
	return ;
}

ICharacter::ICharacter( const ICharacter& )
{
	//std::cout << "ICharacter copy constructor called" << std::endl;
	return ;
}

ICharacter &ICharacter::operator=( const ICharacter& )
{
	//std::cout << "ICharacter copy assignment operator called" << std::endl;
	return (*this);
}

ICharacter::~ICharacter(void)
{
	//std::cout << "ICharacter destructor called" << std::endl;
	return ;
}

ICharacter::ICharacter(std::string name) : _name(name)
{
	//std::cout << "ICharacter " << this->_name << " constructor called" << std::endl;
	return ;
}
