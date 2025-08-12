#include "vect2.hpp"

// Constructors
vect2::vect2() : x(0), y(0) {}
vect2::vect2(int x_, int y_) : x(x_), y(y_) {}

// operator[]
int& vect2::operator[](int i) {
    return (i == 0) ? x : y;
}

const int& vect2::operator[](int i) const {
    return (i == 0) ? x : y;
}

// Arithmetic operators
vect2 vect2::operator+(const vect2& v) const {
    return vect2(x + v.x, y + v.y);
}

vect2 vect2::operator-(const vect2& v) const {
    return vect2(x - v.x, y - v.y);
}

vect2 vect2::operator*(int scalar) const {
    return vect2(x * scalar, y * scalar);
}

// Equality operators
bool vect2::operator==(const vect2& v) const {
    return x == v.x && y == v.y;
}

bool vect2::operator!=(const vect2& v) const {
    return !(*this == v);
}

// Non-member scalar * vector multiplication
vect2 operator*(int scalar, const vect2& v) {
    return vect2(v.x * scalar, v.y * scalar);
}

// Output operator
std::ostream& operator<<(std::ostream& os, const vect2& v) {
    os << "{" << v[0] << ", " << v[1] << "}";
    return os;
}