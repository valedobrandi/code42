#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
int easyfind(T& arr, int b) {
	for (size_t it = 0; it < arr.size(); ++it) {
		if (arr[it] == b) {
			return arr[it];
		}
	}
	throw std::runtime_error("not find");
}

#endif