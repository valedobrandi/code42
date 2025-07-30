#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

Fixed::Fixed(void) : raw(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const raw)
{
	std::cout << "Int constructor called" << std::endl;
	this->raw = raw << 8;
	return ;
}
Fixed::Fixed(float const raw)
{
	std::cout << "Float constructor called" << std::endl;
	this->raw = roundf(raw * 256.0f);
	return ;
}

Fixed::Fixed(const Fixed &other)
{
	this->raw = other.getRawBits();
	return ;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->raw = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
}

int Fixed::getRawBits(void) const
{
	return (this->raw);
}

void Fixed::setRawBits(int const raw)
{
	this->raw = raw;
	return ;
}

float Fixed::toFloat(void) const
{
	return ((float)this->raw / 256.0f);
}

int Fixed::toInt(void) const
{
	return (this->raw >> 8);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed Fixed::operator-(const Fixed &rhs)
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (result);
}

Fixed Fixed::operator+(const Fixed &rhs)
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &rhs)
{
	Fixed	result;

	result.setRawBits((this->getRawBits() * rhs.getRawBits()) >> result.bits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &rhs)
{
	Fixed	result;

	result.setRawBits((this->getRawBits() << result.bits) / rhs.getRawBits());
	return (result);
}

Fixed &Fixed::operator++()
{
	this->raw += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->raw += 1;
	return temp;
}

Fixed &Fixed::operator--()
{
	this->raw -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->raw -= 1;
	return temp;
}

const Fixed &Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	return (lhs > rhs) ? lhs : rhs;
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs)
{
	return (lhs > rhs) ? lhs : rhs;
}

const Fixed &Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	return (lhs < rhs) ? lhs : rhs;
}

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs)
{
	return (lhs < rhs) ? lhs : rhs;
}