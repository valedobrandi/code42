#include "set.hpp"

set::set(searchable_bag* bag) : bag(bag)
{

}
set::set(const set& other) : bag(other.bag)
{

}
set::~set()
{

}
set& set::operator=(const set& other)
{
    if (this != &other) bag = other.bag;
    return *this;
}

void set::insert(int v)
{
    if (!bag->has(v)) bag->insert(v);
}
void set::insert(int* data, int v)
{
    for (int i = 0; i < v; ++i)
    {
        if(!bag->has(data[i]))
            bag->insert(data[i]);
    }
}
void set::print() const
{
    bag->print();
}
void set::clear()
{
    bag->clear();
}
bool set::has(int value) const
{
    return (bag->has(value));
}