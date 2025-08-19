#include "set.hpp"

set::set(searchable_bag* bag): bag(bag) {}
set::set(const set& other): bag(other.bag) {}
set& set::operator=(const set& other) {
    // Copy the pointer
    if (this != &other) bag = other.bag;
    return *this;
}
set::~set() {}

// insert(int): inserts a single value if it’s not already in the set
void set::insert(int v) {
    if (!bag->has(v)) bag->insert(v);
}

// 'data' = pointer to int array, 'v' = number of elements
void set::insert(int* data, int v) {
    if (!data || v < 0) return;
    for (int i = 0; i < v; ++i) {
        // Insert only if value not already present
        if (!bag->has(data[i])) {
            bag->insert(data[i]);
        } 
    }
}
void set::print() const {bag->print();}
void set::clear() {bag->clear();}

// has(): checks if a value is in the set by delegating to the bag
bool set::has(int value) const {return bag->has(value);}