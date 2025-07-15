#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    std::cout << "=== FIXED POINT NUMBER TESTS ===" << std::endl;
    
    // Test 1: Basic construction and output
    std::cout << "\n1. Basic Construction and Output:" << std::endl;
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);
    
    std::cout << "a (default): " << a << std::endl;
    std::cout << "b (int 10): " << b << std::endl;
    std::cout << "c (float 42.42): " << c << std::endl;
    std::cout << "d (copy of b): " << d << std::endl;
    
    // Test 2: Assignment operator
    std::cout << "\n2. Assignment Operator:" << std::endl;
    a = Fixed(1234.4321f);
    std::cout << "a after assignment: " << a << std::endl;
    
    // Test 3: Comparison operators
    std::cout << "\n3. Comparison Operators:" << std::endl;
    Fixed x(5.5f);
    Fixed y(3.3f);
    Fixed z(5.5f);
    
    std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
    std::cout << "x > y: " << (x > y) << std::endl;
    std::cout << "x < y: " << (x < y) << std::endl;
    std::cout << "x >= z: " << (x >= z) << std::endl;
    std::cout << "x <= z: " << (x <= z) << std::endl;
    std::cout << "x == z: " << (x == z) << std::endl;
    std::cout << "x != y: " << (x != y) << std::endl;
    
    // Test 4: Arithmetic operators
    std::cout << "\n========= 4. Arithmetic Operators ===========" << std::endl;
    Fixed num1(10.5f);
    Fixed num2(2.5f);
    
    std::cout << "num1 = " << num1 << ", num2 = " << num2 << std::endl;
    std::cout << "num1 + num2 = " << (num1 + num2) << std::endl;
    std::cout << "num1 - num2 = " << (num1 - num2) << std::endl;
    std::cout << "num1 * num2 = " << (num1 * num2) << std::endl;
    std::cout << "num1 / num2 = " << (num1 / num2) << std::endl;
    
    // Test 5: Increment/Decrement operators
    std::cout << "\n========= 5. Increment/Decrement Operators \n========= " << std::endl;
    Fixed h;
    Fixed const u( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << h << std::endl;
    std::cout << ++h << std::endl;
    std::cout << h << std::endl;
    std::cout << h++ << std::endl;
    std::cout << h << std::endl;
    std::cout << u << std::endl;
    std::cout << Fixed::max( h, u ) << std::endl;
    
    // Test 6: Static min/max functions
    std::cout << "\n========= 6. Static Min/Max Functions =========" << std::endl;
    Fixed min_test1(10.5f);
    Fixed min_test2(20.3f);
    
    std::cout << "min_test1 = " << min_test1 << ", min_test2 = " << min_test2 << std::endl;
    std::cout << "Fixed::min(min_test1, min_test2) = " << Fixed::min(min_test1, min_test2) << std::endl;
    std::cout << "Fixed::max(min_test1, min_test2) = " << Fixed::max(min_test1, min_test2) << std::endl;
    
    // Test with const versions
    const Fixed const_a(15.7f);
    const Fixed const_b(8.2f);
    std::cout << "const_a = " << const_a << ", const_b = " << const_b << std::endl;
    std::cout << "Fixed::min(const_a, const_b) = " << Fixed::min(const_a, const_b) << std::endl;
    std::cout << "Fixed::max(const_a, const_b) = " << Fixed::max(const_a, const_b) << std::endl;
    
    // Test 7: Edge cases
    std::cout << "\n7. Edge Cases:" << std::endl;
    Fixed zero(0);
    Fixed negative(-5.5f);
    Fixed small(0.00390625f);  // 1/256, smallest representable value
    
    std::cout << "zero = " << zero << std::endl;
    std::cout << "negative = " << negative << std::endl;
    std::cout << "small = " << small << std::endl;
    std::cout << "negative + small = " << (negative + small) << std::endl;
    std::cout << "zero == Fixed(0) = " << (zero == Fixed(0)) << std::endl;
    
    // Test 8: Chaining operations
    std::cout << "\n8. Chaining Operations:" << std::endl;
    Fixed chain1(2.0f);
    Fixed chain2(3.0f);
    Fixed chain3(4.0f);
    
    std::cout << "chain1 = " << chain1 << ", chain2 = " << chain2 << ", chain3 = " << chain3 << std::endl;
    std::cout << "chain1 + chain2 * chain3 = " << (chain1 + chain2 * chain3) << std::endl;
    std::cout << "(chain1 + chain2) * chain3 = " << ((chain1 + chain2) * chain3) << std::endl;
    
    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl; 
    return 0;
}