#include "ScavTrap.hpp"

int main( void ) {


    ScavTrap one( "SCAV-3T" );
    ScavTrap two( "SCAV-TR4" );

    one.guardGate();

    one.attack( two.get_name() );
	two.takeDamage(one.get_attackDamage());

	two.attack( one.get_name() );
	one.takeDamage(two.get_attackDamage());

    return 0;
}