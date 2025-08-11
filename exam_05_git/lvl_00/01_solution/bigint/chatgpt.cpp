#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>

class bigint {
private:
    std::string _val; // stored normal order: most significant digit first

    static bool isDigits(const std::string& s) {
        return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
    }

    static void removeLeadingZeros(std::string& s) {
        while (s.size() > 1 && s.front() == '0')
            s.erase(s.begin());
    }

    static std::string addStrings(const std::string& a, const std::string& b) {
        std::string result;
        int carry = 0;
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
        if (_val.size() != other._val.size())
            return (_val.size() < other._val.size()) ? -1 : 1;
        if (_val == other._val)
            return 0;
        return (_val < other._val) ? -1 : 1; // lexicographic works for equal-length numbers
    }

public:
    bigint() : _val("0") {}
    bigint(unsigned int i) { _val = std::to_string(i); }
    bigint(const std::string& s) { _val = isDigits(s) ? s : "0"; removeLeadingZeros(_val); }
    bigint(const bigint& other) = default;
    bigint& operator=(const bigint& rhs) = default;

    bigint operator+(const bigint& other) const {
        return bigint(addStrings(_value, other._value));
    }
    bigint& operator+=(const bigint& other) {
        _value = addStrings(_value, other._value);
        return *this;
    }

    bigint operator++(int) { bigint tmp(*this); *this += bigint(1); return tmp; }
    bigint& operator++() { *this += bigint(1); return *this; }

    bool operator==(const bigint& other) const { return _val == other._val; }
    bool operator!=(const bigint& other) const { return !(*this == other); }
    bool operator<(const bigint& other) const { return compare(other) < 0; }
    bool operator>(const bigint& other) const { return compare(other) > 0; }
    bool operator<=(const bigint& other) const { return compare(other) <= 0; }
    bool operator>=(const bigint& other) const { return compare(other) >= 0; }

    bigint operator<<(unsigned int y) const {
        if (_val == "0") return *this;
        return bigint(_val + std::string(y, '0'));
    }
    bigint operator>>(unsigned int y) const {
        if (y >= _val.size()) return bigint(0);
        return bigint(_val.substr(0, _val.size() - y));
    }
    bigint& operator<<=(unsigned int y) { *this = *this << y; return *this; }
    bigint& operator>>=(unsigned int y) { *this = *this >> y; return *this; }

    void print(std::ostream& os) const { os << _val; }
    friend std::ostream& operator<<(std::ostream& os, const bigint& bi) {
        bi.print(os);
        return os;
    }
};
