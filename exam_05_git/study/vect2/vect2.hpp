#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2 {
public:
    int x, y;

    vect2();                 // default constructor
    vect2(int x, int y);     // parameterized constructor

    int& operator[](int i);         // access operator (non-const)
    const int& operator[](int i) const; // access operator (const)

    vect2 operator+(const vect2& v) const;
    vect2 operator-(const vect2& v) const;
    vect2 operator*(int scalar) const;

    bool operator==(const vect2& v) const;
    bool operator!=(const vect2& v) const;
};

// Scalar multiplication commutative support
vect2 operator*(int scalar, const vect2& v);

std::ostream& operator<<(std::ostream& os, const vect2& v);

#endif