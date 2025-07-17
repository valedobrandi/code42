#ifndef DIAMONDTRAP_CLASS_H
#define DIAMONDTRAP_CLASS_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class DiamondTrap: public FragTrap, public ScavTrap {

	private:

		std::string _name;

    public:

        DiamondTrap( void );
        DiamondTrap( DiamondTrap const & src );
        ~DiamondTrap( void );
        DiamondTrap & operator=( DiamondTrap const & rhs );

        DiamondTrap( std::string name );


		void attack(const std::string &target);
		void whoAmI( void );

		std::string getName() const;
    };

#endif