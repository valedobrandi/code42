#ifndef ICE_CLASS_H
#define ICE_CLASS_H

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
    public:

        Ice( void );
        Ice( const Ice& other );
        Ice& operator=( const Ice& rhs );
        virtual ~Ice( void );

        Ice(std::string const & type);

		virtual AMateria* clone() const;
        void use(ICharacter& target);

};

#endif