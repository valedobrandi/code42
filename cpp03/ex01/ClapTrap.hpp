#ifndef CLAPTRAP_CLASS_H
#define CLAPTRAP_CLASS_H

#include <iostream>

class ClapTrap {

    protected:

        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;

        bool status( void );

    public:

        ClapTrap( void );                        
        ClapTrap( ClapTrap const & src );            
        ~ClapTrap( void );                          
        ClapTrap & operator=( ClapTrap const & rhs ); 
        
        ClapTrap( std::string name );


        void attack( const std::string& target );
        void takeDamage( unsigned int amount );
        void beRepaired( unsigned int amount );
};      

#endif