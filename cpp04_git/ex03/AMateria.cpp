#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(void) : _type("")
{
	//std::cout << "AMateria default constructor called" << std::endl;
	return ;
}

AMateria::AMateria(const AMateria &other)
{
	//std::cout << "AMateria copy constructor called" << std::endl;
	this->_type = other._type;
	return ;
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	//std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

AMateria::~AMateria(void)
{
	//std::cout << "AMateria destructor called" << std::endl;
	return ;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	//std::cout << "AMateria " << this->_type << " constructor called" << std::endl;
	return ;
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "" << target.getName() << std::endl;
    return ;
}
