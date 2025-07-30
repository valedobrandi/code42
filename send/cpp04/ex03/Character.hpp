#ifndef CHARACTER_CLASS_H
#define CHARACTER_CLASS_H

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

struct t_unequip
{
	AMateria* drop;
	t_unequip* next;
};


class Character : public ICharacter
{
    public:

        AMateria* inventory[4];
		t_unequip* dropped;

        Character( void );
        Character( const Character& other );
        Character& operator=( const Character& rhs );
        virtual ~Character( void );

        Character( std::string name );

		std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif