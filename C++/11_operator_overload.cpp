#include <iostream>

class Integer {

    public:

        Integer( int const n );
        ~Integer( void );

        int getValue( void ) const;

        Integer &   operator=( Integer const & rhs );
        Integer     operator+( Integer const & rhs ) const;

    private:

        int _n;
};

Integer::Integer( int const n ): _n( n ) {
    std::cout << "Constructor called with value " << this->_n << std::endl;
    return;
}

Integer::~Integer( void ) {
    std::cout << "Destructor called with value " << this->_n << std::endl;
    return;
}

int Integer::getValue( void ) const {
    return this->_n;
}

Integer &   Integer::operator=( Integer const & rhs ) {
    std::cout << "Assignation operator called from " << this->_n;
    std::cout << " to " << rhs.getValue() << std::endl;

    this->_n = rhs.getValue();

    return *this;
}

Integer     Integer::operator+( Integer const & rhs ) const {
    std::cout << "Addition operator called from " << this->_n;
    std::cout << " and " << rhs.getValue() << std::endl;

    return Integer( this->_n + rhs.getValue() );
}

std::ostream & operator<<( std::ostream & o, Integer const & rhs ) {
    o << rhs.getValue();

    return o;
}

int main( void ) {

    Integer x( 30 );
    Integer y( 10 );
    Integer z( 0 );

    std::cout << "Value of x : " << x << std::endl;
    std::cout << "Value of x : " << y << std::endl;

    y = Integer( 12 );

    std::cout << "Value of x : " << y << std::endl;
    std::cout << "Value of x : " << z << std::endl;

    z = x + y;

    std::cout << "Value of x : " << z << std::endl;
    return 0;
}
