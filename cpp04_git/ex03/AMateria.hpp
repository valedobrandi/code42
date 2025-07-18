#ifndef AMATERIA_CLASS_H
#define AMATERIA_CLASS_H

#include <iostream>

class ICharacter;

class AMateria
{
    protected:

        std::string _type;
    
    public:
    
        AMateria( void );
        AMateria( const AMateria& other );
        AMateria& operator=( const AMateria& rhs );
        virtual ~AMateria( void );
    
        AMateria(std::string const & type);

        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif