#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice(void) : AMateria()
{
    //std::cout << "Ice default constructor called" << std::endl;
    this->_type = "ice";
    return;
}

Ice::Ice(const Ice &other) : AMateria( other )
{
    //std::cout << "Ice copy constructor called" << std::endl;
    this->_type = other._type;
    return;
}

Ice &Ice::operator=(const Ice &rhs)
{
    //std::cout << "Ice copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    return *this;
}

Ice::~Ice(void)
{
    //std::cout << "Ice destructor called" << std::endl;
    return;
}

Ice::Ice(std::string const & type) : AMateria()
{
    this->_type = type;
    //std::cout << "Ice "<< this->_type << " constructor called" << std::endl;
    return ;

}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
    return ;
}