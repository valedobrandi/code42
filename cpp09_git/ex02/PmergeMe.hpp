#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <list>
#include <string>
#include <iostream>

typedef std::deque<int>::iterator dequeIntIt;
typedef std::list<int>::iterator listIntIt;

class PmergeMe {
    public:

        PmergeMe(void);
        ~PmergeMe(void);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);

        long long dequeSort(std::deque<int>&);
        long long listSort(std::list<int> &);
};

#endif