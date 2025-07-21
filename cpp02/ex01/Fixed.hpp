#ifndef FIXED_CLASS_H
#define FIXED_CLASS_H

#include <ostream>

class Fixed {

    private:

        int raw;
        static const int bits = 8; 

    public:

        Fixed( void );
        Fixed( const Fixed& other );
        Fixed& operator=( const Fixed& other );
        ~Fixed( void );
        
        Fixed( int const raw );
        Fixed( float const raw );

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;


};
        std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif