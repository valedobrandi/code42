#include "ClapTrap.hpp"

int main( void ) {
    
    ClapTrap one( "1" );
    ClapTrap two( "2" );

    one.attack( "2" );

    two.attack( "1" );
    two.attack( "1" );
    two.attack( "1" );
    two.attack( "1" );
    two.attack( "1" );
    two.attack( "1" );
    two.attack( "1" );
    two.attack( "1" );
    two.attack( "1" );
    two.attack( "1" );
    two.attack( "1" );

    one.takeDamage( 9 );
    two.takeDamage( 5 );

    one.beRepaired( 9 );
    two.beRepaired( 5 );

    one.takeDamage( 4 );
    one.beRepaired( 5 );

    one.attack( "2" );
    two.takeDamage( 10 );
    two.attack( "1" );

    return 0;
}