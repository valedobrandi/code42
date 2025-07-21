#ifndef BRAIN_CLASS_H
# define BRAIN_CLASS_H

#include <iostream>

class Brain {

    public:

    std::string ideas[100];

    Brain( void );
    Brain( const Brain& other );
    Brain& operator=( const Brain& rhs );
    ~Brain( void );

};


#endif