#ifndef SCAVTRAP_CLASS_H
#define SCAVTRAP_CLASS_H

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap: public ClapTrap {
    public:
        ScavTrap( void );
        ~ScavTrap( void );
        ScavTrap( ScavTrap const & src );
        ScavTrap & operator=( ScavTrap const & rhs );

        ScavTrap( std::string name );

		std::string getName() const;
        void guardGate( void );
		void attack(const std::string &target);
};

#endif