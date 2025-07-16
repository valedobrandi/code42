#ifndef FRAGTRAP_CLASS_H
#define FRAGTRAP_CLASS_H

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap: virtual public ClapTrap {
    public:
        FragTrap( void );
        FragTrap( FragTrap const & src );
        ~FragTrap( void );
        FragTrap & operator=( FragTrap const & rhs );

        FragTrap( std::string name );

		std::string get_name() const;
        void highFivesGuys( void );
};

#endif