#include <iostream>
#include <string>
#include <exception>
#include "Array.hpp" // Make sure your class is in this header

void printLine(const std::string &title)
{
	std::cout << "\n=== " << title << " ===" << std::endl;
}

int main()
{
	{
		try
		{
			printLine("Default constructor");
			Array<int> a;
			std::cout << "a.size(): " << a.size() << std::endl;
			printLine("acess index");
			a[0];
		}
		catch(const std::exception& e)
		{
			std::cerr << "Unexpected exception: " << e.what() << std::endl;
		}

	}
	{
		try
		{
			printLine("Constructor with size");
			Array<int> b(5);
			std::cout << "b.size(): " << b.size() << std::endl;
			for (size_t i = 0; i < b.size(); ++i)
    			b[i] = static_cast<int>(i * 10);
			for (size_t i = 0; i < b.size(); ++i)
				std::cout << "b[" << i << "] = " << b[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}
	{
		try
		{
			printLine("Modifying elements");
			Array<int> b(5);
			std::cout << "b.size(): " << b.size() << std::endl;
			for (size_t i = 0; i < b.size(); ++i)
				b[i] = i * 10;
			for (size_t i = 0; i < b.size(); ++i)
				b[i] *= 10;
			for (size_t i = 0; i < b.size(); ++i)
				std::cout << "b[" << i << "] = " << b[i] << std::endl;

			printLine("Copy constructor");
			Array<int> c(b);
			std::cout << "c.size(): " << c.size() << std::endl;
			for (size_t i = 0; i < c.size(); ++i)
				std::cout << "c[" << i << "] = " << c[i] << std::endl;

			printLine("Modifying copy should not affect original");
			c[0] = 999;
			std::cout << "c[0]: " << c[0] << std::endl;
			std::cout << "b[0]: " << b[0] << std::endl;
			printLine("Assignment operator");
			Array<int> d;
			d = b;
			std::cout << "d.size(): " << d.size() << std::endl;
			for (size_t i = 0; i < d.size(); ++i)
				std::cout << "d[" << i << "] = " << d[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}
	{
		try
		{
			printLine("Working with other types (std::string)");
			Array<std::string> s(3);
			s[0] = "Hello";
			s[1] = "Array";
			s[2] = "Template";
			for (size_t i = 0; i < s.size(); ++i)
				std::cout << "s[" << i << "] = " << s[i] << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Unexpected exception: " << e.what() << std::endl;
		}
	}

	{
		Array<std::string> s(3);
		s[0] = "Hello";
		s[1] = "Array";
		s[2] = "Template";
		// Complex type: std::pair
		printLine("Working with other types (std::pair)");
		Array<std::pair<int, std::string> > p(2);
		p[0] = std::make_pair(1, "one");
		p[1] = std::make_pair(2, "two");

		for (size_t i = 0; i < p.size(); ++i)
			std::cout << "p[" << i << "] = (" << p[i].first << ", " << p[i].second << ")" << std::endl;

		// Const access
		printLine("Working with other types const");
		const Array<std::string> &const_s = s;
		std::cout << "const_s[1] = " << const_s[1] << std::endl;
	}

	return 0;
}
