#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>
#include <iostream>

int main( void ) {

	{
		std::vector<int> arr;
		for (size_t i = 0; i < 10; ++i) {
			arr.push_back(i);
		}
		int find = ::easyfind(arr, 2);
		std::cout << find << std::endl;
		try
		{
			(void) ::easyfind(arr, 11);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}
	{
		std::deque<int> arr;
		for (size_t i = 0; i < 10; ++i) {
			arr.push_back(i);
		}
		int find = ::easyfind(arr, 2);
		std::cout << find << std::endl;
		try
		{
			(void) ::easyfind(arr, 11);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::list<int> arr;
		for (size_t i = 0; i < 10; ++i) {
			arr.push_back(i);
		}
		int find = ::easyfind(arr, 2);
		std::cout << find << std::endl;
		try
		{
			(void) ::easyfind(arr, 11);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return 0;
}