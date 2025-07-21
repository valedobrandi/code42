#include "ScavTrap.hpp"

int main( void ) {


    ScavTrap one( "SCAV-3T" );
    ScavTrap two( "SCAV-TR4" );

    one.guardGate();

    one.attack( two.getName() );
	two.takeDamage(one.get_attackDamage());

	two.attack( one.getName() );
	one.takeDamage(two.get_attackDamage());

    return 0;
}