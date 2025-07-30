#include "Fixed.hpp"
#include <iostream>

int	main(void)
{
	{
		std::cout << "=== FIXED POINT NUMBER TESTS ===" << std::endl;
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	}

	{
		std::cout << "=== FIXED POINT NUMBER TESTS ===" << std::endl;
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << --a << std::endl;
		std::cout << a << std::endl;
		std::cout << a-- << std::endl;

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::min(b, a) << std::endl;
	}

	{
		std::cout << "=== Comparison Operators ===" << std::endl;
		Fixed a(5);
		Fixed b(3);
		Fixed c(5);

		std::cout << "(Fixed a(5) < Fixed b(3)): " << ((a < b) ? "true" : "false") << std::endl;
		std::cout << "(Fixed a(5) > Fixed b(3)): " << ((a > b) ? "true" : "false") << std::endl;
		std::cout << "(Fixed a(5) >= Fixed c(5)): " << ((a >= c) ? "true" : "false") << std::endl;
		std::cout << "(Fixed b(3) <= Fixed a(5)): " << ((b <= a) ? "true" : "false") << std::endl;
		std::cout << "(Fixed a(5) == Fixed c(5)): " << ((a == c) ? "true" : "false") << std::endl;
		std::cout << "(Fixed a(5) != Fixed b(3)): " << ((a != b) ? "true" : "false") << std::endl;

		std::cout << "\nArithmetic Operators:" << std::endl;

		std::cout << "(a - b): " << (a - b) << " (expected: 2)" << std::endl;
		std::cout << "(a + b): " << (a + b) << " (expected: 8)" << std::endl;
		std::cout << "(a * b): " << (a * b) << " (expected: 15)" << std::endl;

		Fixed x(6);
		Fixed y(3);
		std::cout << "(x / y): " << (x / y) << " (expected: 2)" << std::endl;
	}

	return (0);
}