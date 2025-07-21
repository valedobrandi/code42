#include "DiamondTrap.hpp"

int main( void ) {


    DiamondTrap one( "DIAM-3T" );
    DiamondTrap two( "DIAM-TR4" );

    one.highFivesGuys();

    one.attack( two.getName() );
	two.takeDamage(one.get_attackDamage());

	two.attack( one.getName() );
	one.takeDamage(two.get_attackDamage());

    return 0;
}