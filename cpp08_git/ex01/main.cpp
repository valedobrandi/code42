#include "Span.hpp"
#include <iostream>


int main( void ) {

    {
        try
        {
            Span sp = Span(5);
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    {
        try
        {
            Span container(10000);

            for (size_t it = 0; it < 10000; ++it) {
                container.addNumber(it);
            }

            unsigned int max = container.shortestSpan();
            std::cout << max << std::endl;
            unsigned int min = container.longestSpan();
            std::cout << min << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return 0;
}