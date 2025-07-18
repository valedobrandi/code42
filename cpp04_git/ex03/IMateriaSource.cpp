#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

IMateriaSource::IMateriaSource(void) :  index( 0 ), inventory( {0} )
{
    std::cout << "IMateriaSource default constructor called" << std::endl;
    return;
}

IMateriaSource::IMateriaSource(const IMateriaSource &other)
{
    std::cout << "IMateriaSource copy constructor called" << std::endl;
    return;
}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource &rhs)
{
    std::cout << "IMateriaSource copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
    }
    return *this;
}

IMateriaSource::~IMateriaSource(void)
{
    std::cout << "IMateriaSource destructor called" << std::endl;
    return;
}