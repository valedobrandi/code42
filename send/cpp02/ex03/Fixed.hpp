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

        bool operator>(const Fixed& rhs) const;
        bool operator<(const Fixed& rhs) const;
        bool operator>=(const Fixed& rhs) const;
        bool operator<=(const Fixed& rhs) const;
        bool operator==(const Fixed& rhs) const;
        bool operator!=(const Fixed& rhs) const;

        Fixed operator+(const Fixed& rhs);
        Fixed operator-(const Fixed& rhs);
        Fixed operator*(const Fixed& rhs);
        Fixed operator/(const Fixed& rhs);

        Fixed& operator++();
        Fixed operator++( int );
        Fixed& operator--();
        Fixed operator--( int );

        const static Fixed& max(const Fixed& lhs, const Fixed& rhs);
        static Fixed& max(Fixed& lhs, Fixed& rhs);
        const static Fixed& min(const Fixed& lhs, const Fixed& rhs);
        static Fixed& min(Fixed& lhs, Fixed& rhs);
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif