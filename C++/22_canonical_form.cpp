#include <iostream>
std::string message = 
    "Canonical class declaration.";

class Sample {

    public:
        Sample( void );                           /* Canonical */
        Sample( Sample const & src );             /* Canonical */
        ~Sample( void );                          /* Canonical */
        Sample & operator=( Sample const & rhs ); /* Canonical */
};