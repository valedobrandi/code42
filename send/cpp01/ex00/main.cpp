#include "Zombie.hpp"

int main( void ) {
    Zombie* zombie = newZombie("HeapZ");
    
    zombie->announce();
    delete zombie;

    randomChump("StackZ");

    return 0;
}