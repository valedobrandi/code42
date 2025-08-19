#ifndef set_hpp
#define set_hpp

#include "searchable_bag.hpp"

class set : public searchable_bag
{
    public:
        searchable_bag* bag;
        set(searchable_bag* bag);    
        set(const set& other);
        ~set();
        set& operator=(const set& other);
        void insert(int);
        void insert(int*, int);
        void print(void) const;
        void clear();

        virtual bool has(int) const;
};

#endif