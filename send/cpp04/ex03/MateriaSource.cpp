#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) : IMateriaSource()
{
	//std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource &other) : IMateriaSource(other)
{
	//std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
	}
	return ;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this != &rhs)
	{
        for (int i = 0; i < 4; i++) if (this->inventory[i]) delete this->inventory[i];

		for (int i = 0; i < 4; i++)
		{
			if (rhs.inventory[i])
			this->inventory[i] = rhs.inventory[i]->clone();
            else
                this->inventory[i] = NULL;;
		}
	}

	//std::cout << "MateriaSource copy assignment operator called" << std::endl;
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

	//std::cout << "MateriaSource destructor called" << std::endl;
	return ;
}

void MateriaSource::learnMateria(AMateria *m)
{
    if ( !m ) return;

    int i = 0;

	while (i < 4)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			return;
		}
        i++;
	}

    delete m;
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