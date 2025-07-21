#ifndef MATERIASOURCE_CLASS_H
#define MATERIASOURCE_CLASS_H

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource
{
    public:

        AMateria* inventory[4];

        MateriaSource( void );
        MateriaSource( const MateriaSource& other );
        MateriaSource& operator=( const MateriaSource& rhs );
        virtual ~MateriaSource( void );

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);

};

#endif