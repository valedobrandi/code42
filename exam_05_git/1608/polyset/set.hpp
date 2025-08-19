#ifndef set_HPP
#define set_HPP

#include "searchable_bag.hpp"
#include <iostream>

class set : virtual public searchable_bag {
    public:

        searchable_bag* bag;

        set(searchable_bag* bag);
        set(const set& other);
        ~set();
        set& operator=(const set& other);

        void insert(int v);
        void insert(int* data, int v);
        void print() const;
        void clear();
        virtual bool has(int) const;

};

#endif