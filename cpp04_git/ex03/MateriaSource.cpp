#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) : IMateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource &other) : IMateriaSource(other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i];
	}
	return ;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		IMateriaSource::operator=(rhs);
		for (int i = 0; i < 4; i++)
		{
			if (rhs.inventory[i])
				this->inventory[i] = rhs.inventory[i];
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
		}

	}
	std::cout << "MateriaSource destructor called" << std::endl;
	return ;
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m->clone();
			return ;
		}
	}
	return ;
};

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] && this->inventory[i]->getType() == type)
		{
			return (this->inventory[i]->clone());
		}
	}

	return (0);
}