#include "FragTrap.hpp"

int main( void ) {


    FragTrap one( "SCAV-3T" );
    FragTrap two( "SCAV-TR4" );

    one.highFivesGuys();

    one.attack( two.getName() );
	two.takeDamage(one.get_attackDamage());

	two.attack( one.getName() );
	one.takeDamage(two.get_attackDamage());

    return 0;
}