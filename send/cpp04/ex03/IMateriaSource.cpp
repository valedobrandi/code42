#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

IMateriaSource::IMateriaSource(void)
{
    // std::cout << "IMateriaSource default constructor called" << std::endl;
    return;
}

IMateriaSource::IMateriaSource(const IMateriaSource & )
{
    // std::cout << "IMateriaSource copy constructor called" << std::endl;
    return;
}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource & )
{
    // std::cout << "IMateriaSource copy assignment operator called" << std::endl;
    return *this;
}

IMateriaSource::~IMateriaSource(void)
{
    // std::cout << "IMateriaSource destructor called" << std::endl;
    return;
}