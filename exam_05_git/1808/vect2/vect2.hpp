#ifndef vect2_hpp
#define vect2_hpp

#include <ostream>

class vect2 
{
    public:
        int a, b;

        vect2(int a = 0, int b = 0);
        vect2(const vect2& other);
        vect2& operator=(const vect2& other);
        ~vect2();

        int& operator[](int);
        int operator[](const int) const;

        vect2 operator+(int i) const;
        vect2 operator-(int i) const;
        vect2 operator*(int i) const;

        vect2 operator+(vect2 other) const;
        vect2 operator-(vect2 other) const;
        vect2 operator*(vect2 other) const;

        vect2& operator+=(int);
        vect2& operator-=(int);

        vect2& operator+=(vect2 other);
        vect2& operator-=(vect2 other);

        vect2& operator++();
        vect2& operator--();

        vect2 operator++(int);
        vect2 operator--(int);

        bool operator==(vect2 other) const;
        bool operator!=(vect2 other) const;

        friend std::ostream& operator<<(std::ostream& os, const vect2& other);
        friend vect2 operator+(int i, vect2 other);
        friend vect2 operator-(int i, vect2 other);
        friend vect2 operator*(int i, vect2 other);

};


#endif