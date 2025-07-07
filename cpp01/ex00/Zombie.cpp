#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( std::string name ) {
    this->name = name;
}

void    Zombie::announce( void ) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}


Zombie::~Zombie( void ) {
    std::cout << this->name << ": destroyed" << std::endl;
    return ;
}