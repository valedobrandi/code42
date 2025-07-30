#include "DiamondTrap.hpp"

int main(void) {

    std::cout << "=== CONSTRUCTOR ===" << std::endl;
    DiamondTrap one("DIAM-3T");
    std::cout << std::endl;

    std::cout << "=== INITIAL STATS ===" << std::endl;
    std::cout << "DIAM-3T Stats:" << std::endl;
    std::cout << "  Hit Points: " << one.getHitPoints() << " (100 from FragTrap)" << std::endl;
    std::cout << "  Energy Points: " << one.getEnergyPoints() << " (50 from ScavTrap)" << std::endl;
    std::cout << "  Attack Damage: " << one.getAttackDamage() << " (30 from FragTrap)" << std::endl;
    std::cout << std::endl;

    std::cout << "=== TESTING FRAGTRAP ABILITY ===" << std::endl;
    one.highFivesGuys();
    std::cout << std::endl;

    std::cout << "=== TESTING WHOAMI ===" << std::endl;
    one.whoAmI();
    std::cout << std::endl;

    std::cout << "=== TESTING DEAD ===" << std::endl;
    one.takeDamage(99);
    one.beRepaired(1);
    one.takeDamage(2);
    one.beRepaired(100);
	one.takeDamage(1);
	one.highFivesGuys();
	one.attack("DIAM-TR4");
    std::cout << std::endl;

    std::cout << "=== CONSTRUCTOR ===" << std::endl;
    DiamondTrap two("DIAM-TR4");
    std::cout << std::endl;

    std::cout << "=== TESTING ENERGY ===" << std::endl;
    for (int i = 0; i <= 50; i++)
    {
        two.beRepaired(1);
    }
	two.takeDamage(1);
	two.highFivesGuys();
	two.attack("DIAM-3T");
    std::cout << std::endl;
    std::cout << "=== DESTRUCTOR ===" << std::endl;

    return 0;
}