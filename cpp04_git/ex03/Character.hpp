#ifndef CHARACTER_CLASS_H
#define CHARACTER_CLASS_H

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter
{
    public:

        AMateria inventory[4];
        
        Character( void );
        Character( const Character& other );
        Character& operator=( const Character& rhs );
        ~Character( void );

        void Character( std::string name );
};

#endif