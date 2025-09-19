#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
int easyfind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end()) {
        return *it;
    }
	throw std::runtime_error("not found");
}

#endif