#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

void test(Point const a, Point const b, Point const c, Point const p, std::string label) {
    bool result = bsp(a, b, c, p);
    std::cout << label << ": " << (result ? "INSIDE" : "OUTSIDE") << std::endl;
}

int main() {
    Point a(0, 0);
    Point b(4, 0);
    Point c(2, 4);

    test(a, b, c, Point(2, 1), "");

    test(a, b, c, Point(1, 1), "");

    test(a, b, c, Point(3, 1), "");

    test(a, b, c, Point(2, 3), "");

    test(a, b, c, Point(2, 2), "");

    test(a, b, c, Point(2, 0), "");

    test(a, b, c, Point(1, 2), "");

    test(a, b, c, Point(3, 2), "");

    test(a, b, c, Point(0, 0), "");

    test(a, b, c, Point(4, 0), "");

    test(a, b, c, Point(2, 4), "");

    test(a, b, c, Point(5, 5), "");

    test(a, b, c, Point(2, -0.01), "");

    return 0;
}