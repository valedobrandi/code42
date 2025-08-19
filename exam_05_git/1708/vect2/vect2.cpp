#include "vect2.hpp"

vect2::vect2(int x, int y): x(x), y(y) {}
vect2::~vect2() {}
vect2& vect2::operator=(const vect2& other) {
    if (this != &other)
    {
        x = other.x;
        y = other.y;
    }
    return *this;
}

vect2::vect2(const vect2& other) : x(other.x), y(other.y) {}

int& vect2::operator[](int i)
{
    return i == 0 ? x : y;
}

int vect2::operator[](const int i) const
{
    return i == 0 ? x : y;
}

vect2 vect2::operator+(int i) const
{
    vect2 t(x + i, y + i);
    return t;
}

vect2 vect2::operator-(int i) const
{
    vect2 t(x - i, y - i);
    return t;
}

vect2 vect2::operator*(int i) const
{
    vect2 t(x * i, y * i);
    return t;
}

vect2 vect2::operator+(vect2 other) const
{
    vect2 t(x + other.x, y + other.y);
    return t;
}

vect2 vect2::operator-(vect2 other) const
{
    vect2 t(x - other.x, y - other.y);
    return t;
}

vect2 vect2::operator*(vect2 other) const
{
    vect2 t(x * other.x, y * other.y);
    return t;
}

vect2& vect2::operator+=( int i)
{
    x += i;
    y += i;
    return *this;
}

vect2& vect2::operator-=( int i)
{
    x -= i;
    y -= i;
    return *this;
}

vect2& vect2::operator+=(vect2 other)
{
    x += other.x;
    y += other.y;
    return *this;
}

vect2& vect2::operator-=(vect2 other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

/* 
vect2 a(1, 1);
a++;
 */

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

bool vect2::operator==(vect2 other) const
{
    return (other.x == x && other.y == y);
}

bool vect2::operator!=(vect2 other) const
{
    return (other.x != x || other.y != y);
}

std::ostream& operator<<(std::ostream& os, const vect2& other )
{
    os << "{" << other.x << ", " << other.y << "}";
    return os;
}

vect2 operator+(int i, vect2 other)
{
    return (vect2(other.x + i, other.y + i));
}
vect2 operator-(int i, vect2 other)
{
    return (vect2(other.x - i, other.y - i));
}
vect2 operator*(int i, vect2 other)
{
    return (vect2(other.x * i, other.y * i));
}