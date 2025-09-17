#include "bigint.hpp"
#include <algorithm>

// Remove leading zeros (keep one zero if number is zero)
void bigint::remove_leading_zeros() {
    while (digits.length() > 1 && digits[0] == '0') {
        digits.erase(0,1);
    }
}

// Default constructor -> zero
bigint::bigint() : digits("0") {}

// From string constructor (may have leading zeros)
bigint::bigint(const std::string& num) : digits(num) {
    remove_leading_zeros();
}

// From unsigned int constructor
bigint::bigint(unsigned int num) {
    if (num == 0) digits = "0";
    else {
        digits.clear();
        while (num > 0) {
            digits.insert(digits.begin(), '0' + (num % 10));
            num /= 10;
        }
    }
}

// Copy constructor
bigint::bigint(const bigint& other) : digits(other.digits) {}

// Assignment
bigint& bigint::operator=(const bigint& other) {
    if (this != &other) {
        digits = other.digits;
    }
    return *this;
}

// Print function
void bigint::print(std::ostream& os) const {
    os << digits;
}

std::ostream& operator<<(std::ostream& os, const bigint& obj) {
    obj.print(os);
    return os;
}

// Addition helper
bigint bigint::operator+(const bigint& rhs) const {
    std::string result;
    const std::string& a = digits;
    const std::string& b = rhs.digits;

    int carry = 0;
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int x = (i >= 0) ? a[i] - '0' : 0;
        int y = (j >= 0) ? b[j] - '0' : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        result.push_back('0' + (sum % 10));
        i--; j--;
    }
    std::reverse(result.begin(), result.end());
    return bigint(result);
}

bigint& bigint::operator+=(const bigint& rhs) {
    *this = *this + rhs;
    return *this;
}

// Comparison operators
bool bigint::operator==(const bigint& rhs) const {
    return digits == rhs.digits;
}

bool bigint::operator!=(const bigint& rhs) const {
    return !(*this == rhs);
}

bool bigint::operator<(const bigint& rhs) const {
    if (digits.size() != rhs.digits.size())
        return digits.size() < rhs.digits.size();
    return digits < rhs.digits;
}

bool bigint::operator<=(const bigint& rhs) const {
    return *this < rhs || *this == rhs;
}

bool bigint::operator>(const bigint& rhs) const {
    return !(*this <= rhs);
}

bool bigint::operator>=(const bigint& rhs) const {
    return !(*this < rhs);
}

// Digit shift left (<<) — shift digits by adding zeros to right
bigint bigint::operator<<(unsigned int shift) const {
    if (*this == bigint("0")) return *this;
    std::string shifted = digits + std::string(shift, '0');
    return bigint(shifted);
}

// Digit shift right (>>) — shift digits by removing digits from right
bigint bigint::operator>>(unsigned int shift) const {
    if (shift >= digits.size()) return bigint("0");
    std::string shifted = digits.substr(0, digits.size() - shift);
    return bigint(shifted);
}

bigint& bigint::operator<<=(unsigned int shift) {
    *this = *this << shift;
    return *this;
}

bigint& bigint::operator>>=(unsigned int shift) {
    *this = *this >> shift;
    return *this;
}

// Shift with bigint parameter — convert to unsigned int (assuming fits in unsigned int)
bigint bigint::operator<<(const bigint& shift) const {
    // Convert shift to int (assumes it fits in unsigned int)
    unsigned int nshift = 0;
    for (char c : shift.digits) {
        nshift = nshift * 10 + (c - '0');
    }
    return *this << nshift;
}

bigint bigint::operator>>(const bigint& shift) const {
    unsigned int nshift = 0;
    for (char c : shift.digits) {
        nshift = nshift * 10 + (c - '0');
    }
    return *this >> nshift;
}

bigint& bigint::operator<<=(const bigint& shift) {
    unsigned int nshift = 0;
    for (char c : shift.digits) {
        nshift = nshift * 10 + (c - '0');
    }
    *this <<= nshift;
    return *this;
}

bigint& bigint::operator>>=(const bigint& shift) {
    unsigned int nshift = 0;
    for (char c : shift.digits) {
        nshift = nshift * 10 + (c - '0');
    }
    *this >>= nshift;
    return *this;
}

// Increment operators (prefix)
bigint& bigint::operator++() {
    *this += bigint("1");
    return *this;
}

// Increment operators (postfix)
bigint bigint::operator++(int) {
    bigint temp = *this;
    ++(*this);
    return temp;
}
