#ifndef CURE_CLASS_H
#define CURE_CLASS_H

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
    public:

        Cure( void );
        Cure( const Cure& other );
        Cure& operator=( const Cure& rhs );
        virtual ~Cure( void );

        Cure(std::string const & type);

		virtual AMateria* clone() const;
        void use(ICharacter& target);

};

#endif