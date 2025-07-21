#include "ClapTrap.hpp"

int main(void) {

    std::cout << "=== CONSTRUCTOR ===" << std::endl;
    ClapTrap one("DIAM-3T");
    std::cout << std::endl;

    std::cout << "=== INITIAL STATS ===" << std::endl;
    std::cout << "DIAM-3T Stats:" << std::endl;
    std::cout << "  Hit Points: " << one.getHitPoints() << std::endl;
    std::cout << "  Energy Points: " << one.getEnergyPoints() << std::endl;
    std::cout << "  Attack Damage: " << one.getAttackDamage() << std::endl;
    std::cout << std::endl;

    std::cout << "=== TESTING DEAD ===" << std::endl;
    one.takeDamage(9);
    one.beRepaired(1);
    one.takeDamage(2);
    one.beRepaired(10);
    std::cout << std::endl;

    std::cout << "=== CONSTRUCTOR ===" << std::endl;
    ClapTrap two("DIAM-TR4");
    std::cout << std::endl;

    std::cout << "=== TESTING ENERGY ===" << std::endl;
    for (int i = 0; i <= 10; i++) 
    {
        two.beRepaired(1);
    }
    std::cout << std::endl;
    std::cout << "=== DESTRUCTOR ===" << std::endl;

    return 0;
}