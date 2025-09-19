#include "Span.hpp"
#include <iostream>


int main( void ) {
    std::cout << "operator= test:" << std::endl;
    {
        Span one = Span(2);
        one.addNumber(0);
        one.addNumber(1);
        for (size_t it = 0; it < one.container.size(); ++it)
            std::cout << one.container[it] << std::endl;
        Span two = Span(one);
        for (size_t it = 0; it < two.container.size(); ++it)
            std::cout << two.container[it] << std::endl;
    }
    std::cout << "copy operator test:" << std::endl;
    {
        Span one = Span(2);
        one.addNumber(0);
        one.addNumber(1);
        for (size_t it = 0; it < one.container.size(); ++it)
            std::cout << one.container[it] << std::endl;
        Span two(one);
        for (size_t it = 0; it < two.container.size(); ++it)
            std::cout << two.container[it] << std::endl;
    }
    std::cout << "pdf test:" << std::endl;
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
    std::cout << "container full test:" << std::endl;
    {
        try
        {
            Span sp = Span(5);
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            sp.addNumber(99);

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    std::cout << "empty container test:" << std::endl;
    {
        try
        {
            Span sp = Span(5);
            std::cout << sp.shortestSpan() << std::endl;

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    std::cout << "one number container test:" << std::endl;
    {
        try
        {
            Span sp = Span(5);
            sp.addNumber(6);
            std::cout << sp.shortestSpan() << std::endl;

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    std::cout << "addMultipleNumbers test:" << std::endl;
    {
        try
        {
            std::vector<int> numberList;
            for (size_t it = 0; it < 10000; ++it) {
                numberList.push_back(it);
            }
            Span container(10000);
            vectorIntIt start = numberList.begin();
            vectorIntIt end = numberList.end();

            container.addMultipleNumbers(start, end);

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