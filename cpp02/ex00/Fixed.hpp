#ifndef FIXED_CLASS_H
#define FIXED_CLASS_H

class Fixed {

    private:

        int raw;
        static const int bits = 8; 

    public:

        Fixed( void );
        Fixed( const Fixed& other );
        Fixed& operator = ( const Fixed& other );
        ~Fixed( void );
        int getRawBits( void ) const;
        void setRawBits( int const raw );

};

#endif