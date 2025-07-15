#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : name( name ), weapon( NULL ) {}

HumanB::~HumanB( void ) {}

void HumanB::attack( void ) const
{
    if (this->weapon) {
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    } else {
        std::cout << this->name << " has no weapon to attack with!" << std::endl;
    }
    return;
}

void HumanB::setWeapon( Weapon& weapon ) {
    this->weapon = &weapon;
    return;
}