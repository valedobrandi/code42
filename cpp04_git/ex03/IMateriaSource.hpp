#ifndef IMATERIASOURCE_CLASS_H
#define IMATERIASOURCE_CLASS_H

#include "AMateria.hpp"
#include <iostream>

class IMateriaSource
{
    public:

		AMateria* inventory[4];

        IMateriaSource( void );
        IMateriaSource( const IMateriaSource& other );
        IMateriaSource& operator=( const IMateriaSource& rhs );
        virtual ~IMateriaSource( void );

        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif