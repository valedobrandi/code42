#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag() : array_bag() {}
searchable_array_bag::searchable_array_bag(const searchable_array_bag& other) : array_bag(other) {}
searchable_array_bag::~searchable_array_bag() {}
searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag& other) 
{
    if (this != &other)
    {
        array_bag::operator=(other);
    }
    return *this;
}

bool searchable_array_bag::has(int i) const {
    for (int it = 0; it < _size; ++it)
    {
        if (_data[it] == i) return true;
    }
    return false;
}