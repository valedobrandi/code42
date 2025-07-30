#include "ScavTrap.hpp"

int main( void ) {

    std::cout << "=== CONSTRUCTOR ===" << std::endl;
    ScavTrap one( "SCAV-3T" );

    std::cout << std::endl;

    std::cout << "=== INITIAL STATS ===" << std::endl;
    std::cout << "SCAV Stats:" << std::endl;
    std::cout << "  Hit Points: " << one.getHitPoints() << " (100)" << std::endl;
    std::cout << "  Energy Points: " << one.getEnergyPoints() << " (50)" << std::endl;
    std::cout << "  Attack Damage: " << one.getAttackDamage() << " (20)" << std::endl;
    std::cout << std::endl;

    std::cout << "=== TESTING ScavTrap ABILITY ===" << std::endl;
	one.guardGate();
    std::cout << std::endl;

    std::cout << "=== TESTING DEAD ===" << std::endl;
    one.takeDamage(99);
    one.beRepaired(1);
    one.takeDamage(2);
    one.beRepaired(100);
	one.takeDamage(1);
	one.guardGate();
	one.attack("SCAV-TR4");
    std::cout << std::endl;

    std::cout << "=== CONSTRUCTOR ===" << std::endl;
    ScavTrap two( "SCAV-TR4" );
    std::cout << std::endl;

    std::cout << "=== TESTING ENERGY ===" << std::endl;
    for (int i = 0; i <= 50; i++)
    {
        two.beRepaired(1);
    }
	two.takeDamage(1);
	two.guardGate();
	two.attack("SCAV-3T");
    std::cout << std::endl;
    std::cout << "=== DESTRUCTOR ===" << std::endl;

    return 0;
}