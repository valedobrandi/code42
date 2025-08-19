#ifndef set_hpp
#define set_hpp

#include "searchable_bag.hpp"

class set {
    private:
        searchable_bag* bag;
    public:
        set(searchable_bag* bag);
        set(const set& other);
        virtual ~set();
        set& operator=(const set& other);

        void insert(int v);
        void insert(int* data, int v);
        void print() const;
        void clear();

        bool has(int value) const;
};
#endif