#ifndef POINT_CLASS_H
#define POINT_CLASS_H

#include "Fixed.hpp"

class Point {

    private:

        const Fixed _x;
        const Fixed _y ;

    public:

        Point( void );
		Point(const Point& other );
        Point& operator=( const Point& rhs );
        ~Point( void );

        Point( float, float );

        Fixed get_x() const;
        Fixed get_y() const;

        Point operator-(const Point& rhs);

};
std::ostream& operator<<(std::ostream& out, const Point& value);

#endif