#include "DiamondTrap.hpp"

int main( void ) {


    DiamondTrap one( "DIAM-3T" );
    DiamondTrap two( "DIAM-TR4" );

    one.highFivesGuys();

    one.attack( two.get_name() );
	two.takeDamage(one.get_attackDamage());

	two.attack( one.get_name() );
	one.takeDamage(two.get_attackDamage());

    return 0;
}