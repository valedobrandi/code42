#include "vect2.hpp"

vect2::vect2(int x, int y) : _x(x), _y(y) {}

vect2::vect2(const vect2& other): _x(other._x), _y(other._y) {}

vect2::~vect2() {}

vect2& vect2::operator=( const vect2& other) {
    if (this != &other) {
        _x = other._x;
        _y = other._y;
    }
    return *this;
}

int& vect2::operator[](int i) {
    return i == 0 ? _x : _y;
}

int vect2::operator[](int i) const {
    return i == 0 ? _x : _y;
}

vect2 vect2::operator+(int i) {
    vect2 t(_x + i, _y + i);
    return t;
}
vect2 vect2::operator-(int i) {
    vect2 t(_x - i, _y - i);
    return t;
}
vect2 vect2::operator*(int i) {
    vect2 t(_x * i, _y * i);
    return t;
}

vect2 vect2::operator+(vect2 other) {
    vect2 t(_x + other._x, _y + other._y);
    return t;
}
vect2 vect2::operator-(vect2 other) {
    vect2 t(_x - other._x, _y - other._y);
    return t;
}
vect2 vect2::operator*(vect2 other) {
    vect2 t(_x * other._x, _y * other._y);
    return t;
}

vect2& vect2::operator+=(const vect2& other) {
    _x+= other._x;
    _y+= other._y;
    return *this;
}

vect2& vect2::operator-=(const vect2& other) {
    _x-= other._x;
    _y-= other._y;
    return *this;
}

vect2& vect2::operator+=(int i) {
    _x+= i;
    _y+= i;
    return *this;
}

vect2& vect2::operator-=(int i) {
    _x-= i;
    _y-= i;
    return *this;
}

vect2& vect2::operator++() {
    _x++;
    _y++;
    return *this;
}
vect2& vect2::operator--() {
    _x--;
    _y--;
    return *this;
}

vect2 vect2::operator--(int) {
    vect2 t(_x, _y);
    _x--;
    _y--;
    return t;
}
vect2 vect2::operator++(int) {
    vect2 t(_x, _y);
    _x++;
    _y++;
    return t;
}

bool vect2::operator==(vect2 vec) {
    return (_x == vec._x && _y == vec._y);
}
bool vect2::operator!=(vect2 vec) {
    return (_x != vec._x || _y != vec._y);
}

std::ostream& operator<<(std::ostream& os, const vect2& vec) {
    os << "{" << vec._x << ", " << vec._y << "}";
    return os; 
}

vect2 operator+(int i, const vect2& vec) {
    vect2 t(i + vec._x, i + vec._y);
    return t;
}
vect2 operator-(int i, const vect2& vec) {
    vect2 t(i - vec._x, i - vec._y);
    return t;
}
vect2 operator*(int i, const vect2& vec) {
    vect2 t(i * vec._x, i * vec._y);
    return t;
}