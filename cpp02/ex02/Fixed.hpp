#ifndef FIXED_CLASS_H
#define FIXED_CLASS_H

#include <ostream>

class Fixed {

    private:

        int raw;
        static const int bits = 8; 

    public:

        Fixed( void );
        Fixed( int const raw );
        Fixed( float const raw );
        Fixed( const Fixed& other );
        ~Fixed( void );

        Fixed& operator = ( const Fixed& other );
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int toInt( void ) const;


        friend std::ostream& operator<<(std::ostream& out, const Fixed& value);

        friend bool operator>(const Fixed& lhs, const Fixed& rhs);
        friend bool operator<(const Fixed& lhs, const Fixed& rhs);
        friend bool operator>=(const Fixed& lhs, const Fixed& rhs);
        friend bool operator<=(const Fixed& lhs, const Fixed& rhs);
        friend bool operator==(const Fixed& lhs, const Fixed& rhs);
        friend bool operator!=(const Fixed& lhs, const Fixed& rhs);

        friend Fixed operator+(const Fixed& lhs, const Fixed& rhs);
        friend Fixed operator-(const Fixed& lhs, const Fixed& rhs);
        friend Fixed operator*(const Fixed& lhs, const Fixed& rhs);
        friend Fixed operator/(const Fixed& lhs, const Fixed& rhs);

        Fixed& operator++();
        Fixed& operator++( int );
        Fixed& operator--();
        Fixed& operator--( int );

        const static Fixed& max(const Fixed& lhs, const Fixed& rhs);
        static Fixed& max(Fixed& lhs, Fixed& rhs);
        const static Fixed& min(const Fixed& lhs, const Fixed& rhs);
        static Fixed& min(Fixed& lhs, Fixed& rhs);
};
        

#endif