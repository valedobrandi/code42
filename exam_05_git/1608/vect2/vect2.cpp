#include "vect2.hpp"

// initialize
vect2::vect2(int _x, int _y) : x(_x), y(_y) {}

// other initialize
vect2::vect2(const vect2& other): x(other.x), y(other.y) {}

// other reference
vect2& vect2::operator=(const vect2& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;    
}

// deconstructor
vect2::~vect2() {}

// reference index
int& vect2::operator[](int i) 
{ return i == 0 ? x : y; }

// index const 
int vect2::operator[](int i) const { return i == 0 ? x : y; }

// class + value
vect2 vect2::operator+(int i) {
    vect2 t(x + i, y + i);
    return t;
}
vect2 vect2::operator-(int i) {
    vect2 t(x - i, y - i);
    return t;
}
vect2 vect2::operator*(int i) {
    vect2 t(x * i, y * i);
    return t;
}

// class + class return class
vect2 vect2::operator+(vect2 other) {
    vect2 t(x + other.x, y + other.y);
    return t;
}
vect2 vect2::operator-(vect2 other) {
    vect2 t(x - other.x, y - other.y);
    return t;
}
vect2 vect2::operator*(vect2 other) {
    vect2 t(x * other.x, y * other.y);
    return t;
}

vect2& vect2::operator+=(const vect2& other) {
   x += other.x;
   y += other.y;
   return *this;
}
vect2& vect2::operator-=(const vect2& other) {
   x -= other.x;
   y -= other.y;
   return *this;
}

vect2& vect2::operator+=(int i) 
{
    x += i;
    y += i;
    return *this;
}
vect2& vect2::operator-=(int i)
{
    x -= i;
    y -= i;
    return *this;
}

vect2& vect2::operator++() 
{
    x++;
    y++;
    return *this;   
}
vect2& vect2::operator--() 
{
    x--;
    y--;
    return *this;  
}

vect2 vect2::operator++(int) 
{
    vect2 t(x, y);
    x++;
    y++;
    return t;
}
vect2 vect2::operator--(int) 
{
    vect2 t(x, y);
    x--;
    y--;
    return t;
}

bool vect2::operator==(vect2 other) 
{
    return (other.x == x && other.y == y);
}
bool vect2::operator!=(vect2 other) 
{
    return other.x != x || other.y != y;
}

std::ostream& operator<<(std::ostream& os, const vect2& other) 
{
    os << "{" << other.x << ", " << other.y << "}";
    return os;
}
vect2 operator+(int i, const vect2& other) 
{
    vect2 t(i + other.x, i + other.y);
    return t;
}
vect2 operator-(int i, const vect2& other) 
{
    vect2 t(i - other.x, i - other.y);
    return t;
}
vect2 operator*(int i, const vect2& other) 
{
    vect2 t(i * other.x, i * other.y);
    return t;
}