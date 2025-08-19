#include "set.hpp"


set::set(searchable_bag* bag) : bag(bag)
{}    
set::set(const set& other) : bag(other.bag)
{}
set::~set()
{}
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
void set::insert(int* array, int i)
{
    for (int t = 0; t < i; t++)
    {
        if (!bag->has(array[t])) bag->insert(array[t]);
    }
}
void set::print(void) const
{
    bag->print();
}
void set::clear()
{
    bag->clear();
}

bool set::has(int i) const
{
    return bag->has(i);
}