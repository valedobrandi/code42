#include "set.hpp"

set::set(searchable_bag* bag) : bag(bag) {}
set::set(const set& other): bag(other.bag) {}
set::~set() {}
set& set::operator=(const set& other) 
{
    if (this != &other)
    {
        bag = other.bag;
    }
    return *this;
}

void set::insert(int i) 
{
    if (!bag->has(i)) bag->insert(i);
}
void set::insert(int* array, int size) 
{
    for (int it = 0; it < size; ++it)
    {
        if (!bag->has(array[it])) bag->insert(array[it]);
    }
}
void set::print(void) const { bag->print();}
void set::clear() {bag->clear();}

bool set::has(int i) const { return (bag->has(i));}