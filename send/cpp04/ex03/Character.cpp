#include "Character.hpp"
#include <iostream>

Character::Character(void) : ICharacter(), dropped( NULL )
{
	for (int i = 0; i < 4; i++) this->inventory[i] = NULL;
	
	this->_name = "";
	//std::cout << "Character default constructor called" << std::endl;
	return ;
}

Character::Character(const Character &other) : ICharacter(other)
{
	this->_name = other._name;

	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}

	this->dropped = NULL;
	t_unequip* current = other.dropped;
	t_unequip** ptr = &this->dropped;

	while (current) {
		*ptr = new t_unequip;
		(*ptr)->drop = current->drop->clone();
		(*ptr)->next = NULL;
		ptr = &((*ptr)->next);
		current = current->next;
	}


	//std::cout << "Character copy constructor called" << std::endl;
	return ;
}

Character &Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;

        for (int i = 0; i < 4; i++) {
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }

		for (int i = 0; i < 4; i++)
		{
			if (rhs.inventory[i])
				this->inventory[i] = rhs.inventory[i]->clone();
		}

        while (this->dropped) {
            t_unequip* temp = this->dropped;
            this->dropped = this->dropped->next;
            delete temp->drop;
            delete temp;
        }

        this->dropped = NULL;
        t_unequip* current = rhs.dropped;
        t_unequip** ptr = &this->dropped;

        while ( current ) {
            *ptr = new t_unequip;
            (*ptr)->drop = current->drop->clone();
            (*ptr)->next = NULL;
            ptr = &((*ptr)->next);
            current = current->next;
        }
	}

	//std::cout << "Character copy assignment operator called" << std::endl;
	return (*this);
}

Character::~Character(void)
{
	//std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i]) delete this->inventory[i];
	}

	while (dropped) {
		t_unequip* temp = dropped;
		dropped = dropped->next;
        delete temp->drop;
		delete temp;
	}

	return ;
}

Character::Character(std::string name) : ICharacter(), dropped( NULL )
{
	for (int i = 0; i < 4; i++)
	{
		this->inventory[i] = NULL;
	}
	this->_name = name;
	//std::cout << "Character " << this->_name << " constructor called" << std::endl;
	return ;
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			return ;
		}
	}
	return ;
}

void Character::unequip(int idx)
{
    if (idx > 3) return;

	if (this->inventory[idx])
	{
		t_unequip* node = new t_unequip;
		node->drop = this->inventory[idx];
		node->next = NULL;
		if (!dropped) {
			dropped = node;
		} else {
			t_unequip* current = dropped;
			while (current->next)
				current = current->next;
			current->next = node;
		}
		this->inventory[idx] = NULL;
	}

	return ;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx > 3) return;

	if (this->inventory[idx]) this->inventory[idx]->use(target);
	
	return ;
}
