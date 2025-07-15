#include <iostream>

std::string message = "You can write the same function with another parameters";

class Sample {

    public:
        
        Sample( void );
        ~Sample( void );

        void bar( char const c ) const;
        void bar( int const n ) const;
        void bar( float const z ) const;
        void bar( Sample const & i) const;
};

int main( void ) {
    return 0;
}