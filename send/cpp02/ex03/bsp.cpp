#include "Point.hpp"
#include "Fixed.hpp"

bool is_area( float area) {
    return ( area > 0.0f );
}

float triangle_area(Point const point_1, Point const point_2, Point const point_3) {
    float area = 0.5f * (
        point_1.get_x().toFloat() * (point_2.get_y().toFloat() - point_3.get_y().toFloat()) +
        point_2.get_x().toFloat() * (point_3.get_y().toFloat() - point_1.get_y().toFloat()) +
        point_3.get_x().toFloat() * (point_1.get_y().toFloat() - point_2.get_y().toFloat())
    );
    if (area < 0.0f)
        area  = -area;
    return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    float total = triangle_area( a, b, c );
    float triangle_1 = triangle_area( point, b, c );
    float triangle_2 = triangle_area( a, point, c );
    float triangle_3 = triangle_area( a, b, point );

    bool greater_than_0 = is_area( triangle_1 ) && is_area( triangle_2 ) && is_area( triangle_3 );
    bool is_inside = ( triangle_1 + triangle_2 + triangle_3 ) <= total + 0.0001f;

    return greater_than_0 && is_inside;
}