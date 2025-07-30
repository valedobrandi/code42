#include "Fixed.hpp"
#include <iostream>
#include <ostream>
#include <cmath>



Fixed::Fixed( void ): raw(0) {
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed( int const raw ) {
    std::cout << "Int constructor called" << std::endl;
    this->raw = raw << 8;
    return ;
}
Fixed::Fixed( float const raw ) {
    std::cout << "Float constructor called" << std::endl;
    this->raw = roundf(raw * 256.0f);
    return ;
}

Fixed::Fixed( const Fixed& other ) {
    std::cout << "Copy constructor called" << std::endl;
	std::cout << "Copy assignment operator called" << std::endl;
    this->raw = other.getRawBits();
    return ;
}

Fixed& Fixed::operator = ( const Fixed& other ) {
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) this->raw = other.getRawBits();
    return *this;
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

int Fixed::getRawBits( void ) const { return this->raw; }

void Fixed::setRawBits( int const raw ) {
    this->raw = raw;
    return ;
}

float Fixed::toFloat( void ) const {
    return (float)this->raw / 256.0f;
}

int Fixed::toInt( void ) const {
    return this->raw >> 8;
}

std::ostream& operator<<(std::ostream& out, const Fixed& value) {
    out << value.toFloat();
    return out;
}