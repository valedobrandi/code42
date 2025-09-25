#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "deque"
#include "list"
#include <string>
#include <iostream>

typedef std::deque<int>::iterator dequeIntIt;

class PmergeMe {
    public:

        PmergeMe(void);
        ~PmergeMe(void);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);

        void deque_sort(std::deque<int>&);
        void list_sort(std::string);
};

#endif