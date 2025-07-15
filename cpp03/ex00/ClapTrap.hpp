#ifndef CLAPTRAP_CLASS_H
#define CLAPTRAP_CLASS_H

#include <iostream>
class ClapTrap {

    private:

        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;

        bool status( void );

    public:

        ClapTrap( std::string name );
        ~ClapTrap( void );

        void attack( const std::string& target );
        void takeDamage( unsigned int amount );
        void beRepaired( unsigned int amount );
};      

#endif