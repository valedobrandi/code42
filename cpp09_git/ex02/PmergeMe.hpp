#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "deque"
#include "list"
#include <string>
#include <iostream>

typedef std::deque<int>::iterator dequeIt;

class PmergeMe {
    public:
        std::deque<int> deque_container;
        std::list<int> list_container;

        PmergeMe(void);
        ~PmergeMe(void);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);

        void deque_sort(std::string);
        void list_sort(std::string);
};

#endif