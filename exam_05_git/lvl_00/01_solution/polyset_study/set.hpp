#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set {
    private:
        searchable_bag* bag;
    
    public:
        set(searchable_bag* bag);
        set(const set& other);
        virtual ~set();
        set& operator=(const set& other);

        void insert(int);
		void insert(int* array, int size);
		void print() const;
		void clear();
        
        bool has(int value) const;
};

#endif