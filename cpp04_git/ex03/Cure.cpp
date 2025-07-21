#include "AMateria.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure(void) : AMateria()
{
	// std::cout << "Cure default constructor called" << std::endl;
	this->_type = "cure";
	return ;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	// std::cout << "Cure copy constructor called" << std::endl;
	this->_type = other._type;
	return ;
}

Cure &Cure::operator=(const Cure &rhs)
{
	// std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

Cure::~Cure(void)
{
	// std::cout << "Cure destructor called" << std::endl;
	return ;
}

Cure::Cure(std::string const &type)
{
	this->_type = type;
	// std::cout << "Cure " << this->_type << " constructor called" << std::endl;
	return ;
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	return ;
}