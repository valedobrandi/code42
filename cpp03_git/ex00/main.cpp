#include "ClapTrap.hpp"

int main( void ) {

    std::cout << "=== CONSTRUCTOR ===" << std::endl;
    ClapTrap one( "CLAP-3T" );

    std::cout << std::endl;

    std::cout << "=== INITIAL STATS ===" << std::endl;
    std::cout << "CLAP Stats:" << std::endl;
    std::cout << "  Hit Points: " << one.getHitPoints() << " (10)" << std::endl;
    std::cout << "  Energy Points: " << one.getEnergyPoints() << " (10)" << std::endl;
    std::cout << "  Attack Damage: " << one.getAttackDamage() << " (0)" << std::endl;
    std::cout << std::endl;

    std::cout << "=== TESTING DEAD ===" << std::endl;
    one.takeDamage(9);
    one.beRepaired(1);
    one.takeDamage(2);
    one.beRepaired(10);
	one.takeDamage(1);
	one.attack("SCAV-TR4");
    std::cout << std::endl;

    std::cout << "=== CONSTRUCTOR ===" << std::endl;
    ClapTrap two( "CLAP-TR4" );
    std::cout << std::endl;

    std::cout << "=== TESTING ENERGY ===" << std::endl;
    for (int i = 0; i <= 10; i++)
    {
        two.beRepaired(1);
    }
	two.takeDamage(1);
	two.attack("CLAP-3T");
    std::cout << std::endl;
    std::cout << "=== DESTRUCTOR ===" << std::endl;

    return 0;
}