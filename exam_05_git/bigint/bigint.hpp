#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint {
private:
    std::string digits;  // store digits in normal order: most significant digit first

    void remove_leading_zeros();

public:
    // Constructors
    bigint();                        // default = 0
    bigint(const std::string& num); // from string, may have leading zeros
    bigint(unsigned int num);        // from unsigned int
    bigint(const bigint& other);     // copy constructor

    // Assignment
    bigint& operator=(const bigint& other);

    // Output
    void print(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const bigint& obj);

    // Arithmetic
    bigint operator+(const bigint& rhs) const;
    bigint& operator+=(const bigint& rhs);

    // Comparison
    bool operator==(const bigint& rhs) const;
    bool operator!=(const bigint& rhs) const;
    bool operator<(const bigint& rhs) const;
    bool operator<=(const bigint& rhs) const;
    bool operator>(const bigint& rhs) const;
    bool operator>=(const bigint& rhs) const;

    // Digit shift with int and bigint
    bigint operator<<(unsigned int shift) const;
    bigint operator>>(unsigned int shift) const;
    bigint& operator<<=(unsigned int shift);
    bigint& operator>>=(unsigned int shift);

    bigint operator<<(const bigint& shift) const;
    bigint operator>>(const bigint& shift) const;
    bigint& operator<<=(const bigint& shift);
    bigint& operator>>=(const bigint& shift);

    // Increment operators
    bigint& operator++();   // prefix
    bigint operator++(int); // postfix
};

#endif
