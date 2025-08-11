#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>

class bigint {
    private:
        std::string _value;

        static bool isDigit(const std::string& s) {
            return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
        }
        
        static void removeLeadingZeros(std::string& s) {
            while (s.size() > 1 && s.front() == '0')
                s.erase(s.begin());
            if (s.empty()) s = "0";
        }

        static std::string addStrings(const std::string& a, const std::string& b) {
            std::string result;
            int carry = 0;
            //start from the last digit of string a/b
            int i = (int)a.size() - 1, j = (int)b.size() - 1;

            while (i >= 0 || j >= 0 || carry) {
                int sum = carry;
                if (i >= 0) sum += a[i--] - '0';
                if (j >= 0) sum += b[j--] - '0';
                result.push_back((sum % 10) + '0');
                carry = sum / 10;
            }

            std::reverse(result.begin(), result.end());
            return result;
        }

        int compare(const bigint& other) const {
            if (_value.size() != other._value.size())
                return (_value.size() < other._value.size() ? -1 : 1);
            if (_value == other._value)
                return 0;
            return _value < other._value ? -1 : 1;
        }

        unsigned int toUInt() const {
            return static_cast<unsigned int>(std::stoull(_value));
        }

    public:
        bigint() : _value("0") {};
        bigint(unsigned int i) {_value = std::to_string(i);}
        bigint(const std::string& s) {
            _value = isDigit(s) ? s : "0"; 
            removeLeadingZeros(_value);    
        }
        bigint(const bigint& other) = default;
        bigint& operator=(const bigint& rhs) = default;

        bigint operator+(const bigint& other) const {
            return bigint(addStrings(_value, other._value));
        }

        bigint& operator+=(const bigint& other) {
            _value = addStrings(_value, other._value);
            return *this;
        }

        bigint operator++(int) { bigint tmp(*this); *this += bigint(1); return tmp;}
        bigint& operator++() {*this += bigint(1); return *this;}

        bool operator==(const bigint& other) const { return _value == other._value;}
        bool operator!=(const bigint& other) const { return !(*this == other);}
        bool operator<(const bigint& other) const { return compare(other) < 0;}
        bool operator>(const bigint& other) const { return compare(other) > 0;}
        bool operator<=(const bigint& other) const { return compare(other) <= 0;}
        bool operator>=(const bigint& other) const { return compare(other) >= 0;}

        bigint operator<<(unsigned int y) const {
            if (_value == "0") return *this;
            return bigint(_value + std::string(y, '0'));
        }
        
        bigint operator>>(unsigned int y) const {
            if (y >= _value.size()) return bigint(0);
            return bigint(_value.substr(0, _value.size() - y));
        }

        bigint& operator<<=(unsigned int y) { return *this = *this << y; return *this;}
        bigint& operator>>=(unsigned int y) { return *this = *this >> y; return *this;}

        bigint operator<<(const bigint& y) const { return *this << y.toUInt(); }
        bigint operator>>(const bigint& y) const { return *this >> y.toUInt(); }
        bigint& operator<<=(const bigint& y) { return *this <<= y.toUInt(); }
        bigint& operator>>=(const bigint& y) { return *this >>= y.toUInt(); }

        void print(std::ostream& os) const {os << _value;}

        friend std::ostream& operator<<(std::ostream& os, const bigint& big) {
            big.print(os);
            return (os);
        }
};
