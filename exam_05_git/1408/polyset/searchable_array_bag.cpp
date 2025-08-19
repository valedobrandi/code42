#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag() :array_bag() {};
searchable_array_bag::searchable_array_bag( const searchable_array_bag& other) :array_bag(other) {};
searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag& other) {
    if (this != &other) {
        array_bag::operator=(other);
    }

    return *this;
}
searchable_array_bag::~searchable_array_bag() {};

// has(): searches for an integer inside the array
bool searchable_array_bag::has(int i) const {
    // Loop through all stored elements
    for (int at = 0; at < _size; ++at) {
        if (_data[at] == i) return true;
    }
    return false;
}