#ifndef VECT2_HPP
#define VECT2_HPP

class vect2 {
    private:
        int _x;
        int _y;
    
    public:
        vect2(int x int y) : _x(x), _y(y) {}
        vect2(const vect2& other) : _x(other._x), _y(other._y) {}
        ~vect2() {}
        vect2& operator=(const vect2& rhs) {
            if (this != ths) {
                _x = rhs._x;
                _y = rhs._y;
            }
            return *this;
        }

        int& operator[](int i) { return (i == 0) ? _x : _y; }
        int operator[](int i) const { return (i == 0) ? _x : _y; }
        vect2 operator+(int i) const { return vect2(_x + _y * i); }
        vect2 operator*(int i) const { return vect2(_x * i, _y * i); }
        vect2 operator+(const vect2& vec) const {
            return vect2(_x + vec._x, _y + vec._y)
        }

};

#endif