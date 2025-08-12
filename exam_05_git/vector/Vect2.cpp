#include "Vect2.hpp"

vect2::vect2(int x, int y): _x(x), _y(y) {};

vect2::vect2(const vect2& other): _x(other._x), _y(other._y) {}

vect2::~vect2() {};

vect2& vect2::operator=(const vect2& rhs) {
    if (*this != rhs) {
        _x = rhs._x;
        _y = rhs._y;
    }
    return *this;
};

// get a const int and return x or y
int& vect2::operator[](const int i) {
    return (i == 0) ? _x : _y;
} 

// get a int and return x or y
int vect2::operator[](int i) const {
    return (i == 0) ? _x : _y;
}

vect2 vect2::operator+(int i) {
    vect2 vect(_x + i, _y + i);
    return vect;
}

vect2 vect2::operator*(int i) {
    vect2 vect(_x * i, _y * i);
    return vect;
}

vect2 vect2::operator-(int i) {
    vect2 vect(_x - i, _y - i);
    return vect;
}

vect2 vect2::operator+(const vect2& vec) {
    vect2 vect(_x + vec._x, _y + vec._y);
    return vect;
}

vect2 vect2::operator*(const vect2& vec) {
    vect2 vect(_x * vec._x, _y * vec._y);
    return vect;
}

vect2 vect2::operator-(const vect2& vec) {
    vect2 vect(_x - vec._x, _y - vec._y);
    return vect;
}

vect2 vect2::operator++(int) {
    vect2 vect(_x, _y);
    _x++;
    _y++;
    return vect;
}

vect2& vect2::operator++() {
    this->_x++;
    this->_y++;
    return *this;
}

vect2 vect2::operator--(int) {
    vect2 vec(_x, _y);
    _x--;
    _y--;
    return vec;
}

vect2& vect2::operator--() {
    this->_x--;
    this->_y--;
    return *this;
}

vect2& vect2::operator+=(int i) {
    this->_x += i;
    this->_y += i;
    return *this;
}

vect2& vect2::operator+=(const vect2& vec) {
    _x += vec._x;
    _y += vec._y;
    return *this;
}

vect2& vect2::operator-=(int i) {
    this->_x -= i;
    this->_y -= i;
    return *this;
}

vect2& vect2::operator-=(const vect2& vec) {
    _x -= vec._x;
    _y -= vec._y;
    return *this;
}

bool vect2::operator==(const vect2& vec) {
    return (_x == vec._x && _y == vec._y);
}

bool vect2::operator!=(const vect2& vec) {
    return (_x != vec._x || _y != vec._y);
}

vect2 operator+(int i, const vect2& vec) {
    vect2 vect(i + vec._x, i + vec._y);
    return vect;
}

vect2 operator*(int i, const vect2& vec) {
    vect2 vect(i * vec._x, i * vec._y);
    return vect;
}

vect2 operator-(int i, const vect2& vec) {
    vect2 vect(i - vec._x, i - vec._y);
    return vect;
}

void vect2::print(std::ostream& os) const {
    os << "{" << this->_x << ", " << this->_y << "}";
}

std::ostream& operator<<(std::ostream& os, const vect2& obj) {
    obj.print(os);
    return os;
}