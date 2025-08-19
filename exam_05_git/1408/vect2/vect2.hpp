#ifndef vect2_hpp
#define vect2_hpp

#include <ostream>

class vect2 {
    public:
        int _x, _y;

        vect2(int x = 0, int y = 0);
        vect2(const vect2& other);
        vect2& operator=(const vect2& other);
        ~vect2();

        int& operator[](int);
        int operator[](int) const;

        vect2 operator+(int i);
        vect2 operator-(int i);
        vect2 operator*(int i);

        vect2 operator+(vect2 other);
        vect2 operator-(vect2 other);
        vect2 operator*(vect2 other);

        vect2& operator+=(const vect2& other);
        vect2& operator-=(const vect2& other);

        vect2& operator+=(int i);
        vect2& operator-=(int i);

        vect2& operator++();
        vect2& operator--();

        vect2 operator++(int);
        vect2 operator--(int);

        bool operator==(vect2 other);
        bool operator!=(vect2 other);

        friend std::ostream& operator<<(std::ostream& os, const vect2& vec);
        friend vect2 operator+(int, const vect2&);
        friend vect2 operator-(int, const vect2&);
        friend vect2 operator*(int, const vect2&);

};

#endif