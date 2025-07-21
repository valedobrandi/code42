#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

IMateriaSource::IMateriaSource(void)
{
    std::cout << "IMateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
    return;
}

IMateriaSource::IMateriaSource(const IMateriaSource &other)
{
    std::cout << "IMateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i];
	}
    return;
}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource &rhs)
{
    std::cout << "IMateriaSource copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		IMateriaSource::operator=(rhs);
		for (int i = 0; i < 4; i++)
		{
			if (rhs.inventory[i])
				this->inventory[i] = rhs.inventory[i];
		}
	}
    return *this;
}

IMateriaSource::~IMateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
		}

	}
    std::cout << "IMateriaSource destructor called" << std::endl;
    return;
}