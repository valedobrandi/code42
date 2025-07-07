#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H
#include <string>

class Zombie {

    private:
    
        std::string name;

    public:

    Zombie( std::string name );
    ~Zombie( void );

    void announce( void );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif