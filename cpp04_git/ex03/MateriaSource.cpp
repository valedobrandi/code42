#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) : IMateriaSource(),  index( 0 ), inventory( {0} )
{
    std::cout << "MateriaSource default constructor called" << std::endl;
    return;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    return;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
    std::cout << "MateriaSource copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
    }
    return *this;
}

MateriaSource::~MateriaSource(void)
{
    std::cout << "MateriaSource destructor called" << std::endl;
    return;
}

void MateriaSource::learnMateria(AMateria*)
{
    if (index > 3) index = 0;
    if (this->inventory[index]) delete this->inventory[index];
    AMateria other = new AMateria(*AMateria);
    this->inventory[index] = other;
    index++;
    return ;
};

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i].getType() == type)
        {
            AMateria other = new AMateria(*AMateria);
            break;
        }
    }
    if ( i = 4 )
        return 0;

    return &other;
}