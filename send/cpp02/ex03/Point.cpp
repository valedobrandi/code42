#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(const Point &other)
{
	this->_x = other._x;
	this->_y = other._y;
	return ;
}

Point &Point::operator=(const Point &rhs)
{
	if (this != &rhs)
	{
		this->_x = rhs._x;
		this->_y = rhs._y;
	}
	return (*this);
}

Point::~Point(void)
{
}

Point::Point(float x, float y) : _x(x), _y(y)
{
}

Fixed Point::get_x() const
{
	return (this->_x);
}

Fixed Point::get_y() const
{
	return (this->_y);
}

Point Point::operator-(const Point &rhs)
{
	Point result(this->get_x().toFloat() - rhs.get_x().toFloat(),
		this->get_y().toFloat() - rhs.get_y().toFloat());
	return (result);
}

std::ostream &operator<<(std::ostream &out, const Point &value)
{
	out << value.get_x().toFloat() << " " << value.get_y().toFloat();
	return (out);
}