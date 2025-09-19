#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

typedef std::vector<int>::const_iterator vectorIntIt;

class Span {
    public:

        unsigned int max_store_size;
        std::vector<int> container;

        Span(void);
        Span(unsigned int n);
        ~Span(void);
        Span( const Span& other);
        Span& operator=( const Span& other);

        void addNumber( unsigned int value );
        unsigned int shortestSpan( void );
        unsigned int longestSpan( void );
        void addMultipleNumbers(vectorIntIt begin, vectorIntIt end);
};

#endif