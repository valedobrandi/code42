#include "exam.hpp"

vect2::vect2(int _x, int _y): x(_x), y(_y) {}

vect2::vect2(const vect2 Other): x(other.x), y(other.y) {}

vect2& vect2::operator=(const vect2& other) {
    if (this != Other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

vect2::~vect2() {}

int& vect2::operator[](int i) {
    return i == 0 ? x : y;
}

int vect2::operator[](int i) const {
    return i == 0 ? x : y;
}

vect2 vect2::operator+(int i) {
    vect2 vect(x + i, y + i);
    return vect;
}

vect2 vect2::operator-(int i) {
    vect2 vect(x - i, y - i);
    return vect;
}

vect2 vect2::operator*(int i) {
    vect2 vect(x * i, y * i);
    return vect;
}

vect2 vect2::operator+(const vect2 t) {
    vect2 vect(x + t.x, y + t.y);
    return vect;
}

vect2 vect2::operator-(const vect2 t) {
    vect2 vect(x - t.x, y - t.y);
    return vect;
}

vect2 vect2::operator*(const vect2 t) {
    vect2 vect(x * t.x, y * t.y);
    return vect;
}

vect2& vect2::operator+=(const vect2& vect) {
    x += vect.x;
    y += vect.y;
}

vect2& vect2::operator-=(const vect2& vect) {
    x -= vect.x;
    y -= vect.y;
}

vect2& vect2::operator-=(int i) {
    x -= i;
    y -= i;
}

vect2& vect2::operator-=(int i) {
    x -= i;
    y -= i;
}

vect2& vect2::operator++(int) {
    vect2 vect(x, y);
    x++;
    y++;
    return vect;
}

vect2& vect2::operator--(int) {
    vect2 vect(x, y);
    x--;
    y--;
    return vect;
}

vect2 vect2::operator++() {
    x++;
    y++;
    return *this;
}
vect2 vect2::operator--() {
    x--;
    y--;
    return *this;
}

bool vect2::operator==(const vect2& vect) {
    return (x == vec.x && y == vec.y);
}

bool vect2::operator!=(const vect2& vect) {
    return (x != vec.x || y != vec.y);
}

vect2 operator+(int i, const vect2& t) {
    vect2 vect(i + t.x, i + t.y);
    return vect;
}

vect2 operator-(int i, const vect2& t) {
    vect2 vect(i - t.x, i - t.y);
    return vect;
}

vect2 operator*(int i, const vect2& t) {
    vect2 vect(i * t.x, i * t.y);
    return vect;
}