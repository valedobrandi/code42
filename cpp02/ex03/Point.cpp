#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

Point::Point( void ): _x( 0 ), _y( 0 ) {}

Point::Point( float x, float y ): _x( x ), _y( y ) {}

Point::~Point( void ) {} 

Point& Point::operator = ( const Point& other ) {
    if (this != &other) {
        this->_x = other._x;
        this->_y = other._y;
    }
    return *this; 
}

Fixed Point::get_x() const {
    return this->_x;
}

Fixed Point::get_y() const {
    return this->_y;
}

Point operator-(const Point& lhs, const Point& rhs) {
    Point result(
        lhs.get_x().toFloat() - rhs.get_x().toFloat(),
        lhs.get_y().toFloat() - rhs.get_y().toFloat()
        );
    return result;
}

std::ostream& operator<<(std::ostream& out, const Point& value) {
    out << value._x.toFloat() << " " << value._y.toFloat();
    return out;
}