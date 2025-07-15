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

    test(a, b, c, Point(2, 1), "✅ Strictly Inside");

    test(a, b, c, Point(1, 1), "✅ Inside near A");

    test(a, b, c, Point(3, 1), "✅ Inside near B");

    test(a, b, c, Point(2, 3), "✅ Inside near C");

    test(a, b, c, Point(2, 2), "✅ Center-ish");

    test(a, b, c, Point(2, 0), "❌ On Edge AB");

    test(a, b, c, Point(1, 2), "❌ On Edge AC");

    test(a, b, c, Point(3, 2), "❌ On Edge BC");

    test(a, b, c, Point(0, 0), "❌ On Vertex A");

    test(a, b, c, Point(4, 0), "❌ On Vertex B");

    test(a, b, c, Point(2, 4), "❌ On Vertex C");

    test(a, b, c, Point(5, 5), "❌ Outside Far");

    test(a, b, c, Point(2, -0.01), "❌ Just Outside Below");

    return 0;
}