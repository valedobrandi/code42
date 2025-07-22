#include "FragTrap.hpp"

int main( void ) {


    std::cout << "=== CONSTRUCTOR ===" << std::endl;
    FragTrap one("FRAG-3T");
    std::cout << std::endl;

    std::cout << "=== INITIAL STATS ===" << std::endl;
    std::cout << "FRAG-3T Stats:" << std::endl;
    std::cout << "  Hit Points: " << one.getHitPoints() << " (100)" << std::endl;
    std::cout << "  Energy Points: " << one.getEnergyPoints() << " (100)" << std::endl;
    std::cout << "  Attack Damage: " << one.getAttackDamage() << " (30)" << std::endl;
    std::cout << std::endl;

    std::cout << "=== TESTING FragTrap ABILITY ===" << std::endl;
    one.highFivesGuys();
    std::cout << std::endl;

    std::cout << "=== TESTING DEAD ===" << std::endl;
    one.takeDamage(99);
    one.beRepaired(1);
    one.takeDamage(2);
    one.beRepaired(100);
	one.takeDamage(1);
	one.highFivesGuys();
	one.attack("FRAG-TR4");
    std::cout << std::endl;

    std::cout << "=== CONSTRUCTOR ===" << std::endl;
    FragTrap two("FRAG-TR4");
    std::cout << std::endl;

    std::cout << "=== TESTING ENERGY ===" << std::endl;
    for (int i = 0; i <= 100; i++)
    {
        two.beRepaired(1);
    }
	two.takeDamage(1);
	two.highFivesGuys();
	two.attack("SCAV-3T");
    std::cout << std::endl;
    std::cout << "=== DESTRUCTOR ===" << std::endl;

    return 0;
}