#include "vect2.hpp"

vect2::vect2(int a, int b) : a(a), b(b) {}
vect2::vect2(const vect2& other) : a(other.a), b(other.b) {}
vect2& vect2::operator=(const vect2& other) {
    if (this != &other) {
        a = other.a;
        b = other.b;  
    }
    return *this;
}
vect2::~vect2() {}

int& vect2::operator[](int i) {
    return i == 0 ? a : b;
}
int vect2::operator[](const int i) const {
    return i == 0 ? a : b;
}

vect2 vect2::operator+(int i) const {
    vect2 t( a + i, b + i);
    return t;
}
vect2 vect2::operator-(int i) const {
    vect2 t( a - i, b - i);
    return t;
}
vect2 vect2::operator*(int i) const {
    vect2 t( a * i, b * i);
    return t;
}

vect2 vect2::operator+(vect2 other) const {
    vect2 t( a + other.a, b + other.b);
    return t;
}
vect2 vect2::operator-(vect2 other) const {
    vect2 t( a - other.a, b - other.b);
    return t;
}
vect2 vect2::operator*(vect2 other) const {
    vect2 t( a * other.a, b * other.b);
    return t;
}

vect2& vect2::operator+=(int i) {
    a += i;
    b += i;
    return *this;
}
vect2& vect2::operator-=(int i) {
    a -= i;
    b -= i;
    return *this;
}

vect2& vect2::operator+=(vect2 other) {
    a += other.a;
    b += other.b;
    return *this;
}
vect2& vect2::operator-=(vect2 other) {
    a -= other.a;
    b -= other.b;
    return *this;
}

vect2& vect2::operator++() {
    a++;
    b++;
    return *this;
}
vect2& vect2::operator--() {
    a--;
    b--;
    return *this;
}

vect2 vect2::operator++(int) {
    vect2 t(a, b);
    a++;
    b++;
    return t;
}
vect2 vect2::operator--(int) {
    vect2 t(a, b);
    a--;
    b--;
    return t;
}

bool vect2::operator==(vect2 other) const {
    return (a == other.a && b == other.b);
}
bool vect2::operator!=(vect2 other) const {
    return (a != other.a || b != other.b);
}

std::ostream& operator<<(std::ostream& os, const vect2& other) {
    os << "{" << other.a << ", " << other.b << "}";
    return os;
}
vect2 operator+(int i, vect2 other) {
    return (vect2( i + other.a, i + other.b));
}
vect2 operator-(int i, vect2 other) {
    return (vect2( i - other.a, i - other.b));
}
vect2 operator*(int i, vect2 other) {
    return (vect2( i * other.a, i * other.b));
}