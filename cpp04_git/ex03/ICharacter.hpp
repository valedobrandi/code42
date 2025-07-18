#ifndef ICHARACTER_CLASS_H
#define ICHARACTER_CLASS_H

#include "AMateria.hpp"
#include <iostream>

class ICharacter
{
    private:
        
        std::string _name;
        
    public:

        AMateria* inventory[4];
        
        ICharacter( void );
        ICharacter( const ICharacter& other );
        ICharacter& operator=( const ICharacter& rhs );
        virtual ~ICharacter( void );

        ICharacter( std::string name );
        
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

#endif