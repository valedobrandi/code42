class vect2  {
    public:
        int x, y;

        vect2(int x = 0, int y = 0);
        vect2(const vect2 Other);
        vect2& operator=(const vect2& other);
        ~vect2();

        // []
        int& operator[](int i);
        int operator[](int i) const;

        // + - *
        vect2 operator+(int i);
        vect2 operator*(int i);
        vect2 operator-(int i);

        vect2 operator+(const vect2 vect);
        vect2 operator*(const vect2 vect);
        vect2 operator-(const vect2 vect);

        // += -=
        vect2& operator+=(const vect2& vect);
        vect2& operator-=(const vect2& vect);

        vect2& operator+=(int i);
        vect2& operator-=(int i);

        // ++ --
        vect2& operator++();
        vect2& operator--();

        vect2 operator++(int i);
        vect2 operator--(int i);

        // == !=
        bool operator==(const vect2& vect);
        bool operator!=(const vect2& vect);

        void print(std::ostream& os) const {
            std::cout << "{" << x << "," << y << "}";
        }

        friend std::ostream operator <<(std::ostream& os, const vect2& obj) {
            obj.print();
            return os;
        }

        friend vect2 operator+(int i, const vect2& vect);
        friend vect2 operator-(int i, const vect2& vect);
        friend vect2 operator*(int i, const vect2& vect);
};