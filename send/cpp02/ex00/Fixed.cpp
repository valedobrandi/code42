#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed( void ): raw(0) {
    std::cout << "Default constructor called" << std::endl;
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
    if (this != &other)
        this->raw = other.getRawBits();
    return *this;
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->raw;
}

void Fixed::setRawBits( int const raw ) {
    this->raw = raw;
    return ;
}