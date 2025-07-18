#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure(void) : AMateria()
{
    std::cout << "Cure default constructor called" << std::endl;
    his->_type = "";
    return;
}

Cure::Cure(const Cure &other)
{
    std::cout << "Cure copy constructor called" << std::endl;
    this->type = other.type;
    return;
}

Cure &Cure::operator=(const Cure &rhs)
{
    std::cout << "Cure copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return *this;
}

Cure::~Cure(void)
{
    std::cout << "Cure destructor called" << std::endl;
    return;
}

Cure::Cure(std::string const & type) :  _type( type )
{
    std::cout << "Cure "<< this->_type << " constructor called" << std::endl;
    return ;

}

void Cure::use(ICharacter& target) 
{
    std::string << "* heals " << target.getName()  << "’s wounds *" <<std::endl;
    return ;
}