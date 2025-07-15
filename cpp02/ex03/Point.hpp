#ifndef POINT_CLASS_H
#define POINT_CLASS_H

#include "Fixed.hpp"

class Point {

    private:

        Fixed _x;
        Fixed _y;
    
    public:

        Point( void );
        Point( float, float );
        ~Point( void );

        Fixed get_x() const;
        Fixed get_y() const;

        Point& operator = ( const Point& other );
        friend Point operator-(const Point& lhs, const Point& rhs);

        friend std::ostream& operator<<(std::ostream& out, const Point& value);

};

#endif