#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA(void) {}

void HumanA::attack(void) const
{
    std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
    return;
}