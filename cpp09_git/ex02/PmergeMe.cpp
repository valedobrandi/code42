#include "PmergeMe.hpp"
#include <algorithm>
#include <sys/time.h>


PmergeMe::PmergeMe(void)
{
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe::PmergeMe(const PmergeMe &/* other */)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &/* other */)
{
    return *this;
}

std::deque<int> jacobs_index(int n) {
    std::deque<int> index;
    if (n == 0) return index;

    index.push_back(0);
    if (n == 1) return index;

    index.push_back(1);
    if (n == 2) return index;

    int j0 = 0, j1 = 1;
    while (true) {
        int next = j1 + 2 * j0;
        if (next >= n) break;
        if (index.back() != next) {
            index.push_back(next);
        }
        j0 = j1;
        j1 = next;
    }
    std::deque<int> used(n, 0);
    for (dequeIntIt it = index.begin(); it != index.end(); ++it) {
        used[*it] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            index.push_back(i);
        }
    }
    return index;
}

void ford_algorithm_deque(std::deque<int> &container) {
    size_t n = container.size();
    
    if (n <= 1) return;
    
    std::deque<int> A, B;
    size_t i = 0;

    while (i+1 < n) {
        if (container[i] > container[i+1]) {
            A.push_back(container[i]);
            B.push_back(container[i+1]);
        } else {
            A.push_back(container[i+1]);
            B.push_back(container[i]);
        }
        i+= 2;
    }

    if (i < n) A.push_back(container[i]);

    ford_algorithm_deque(A);

    std::deque<int> jacob_seq = jacobs_index(B.size());

    for (dequeIntIt it = jacob_seq.begin(); it != jacob_seq.end(); ++it) {
        int idx = *it;
        dequeIntIt pos = std::lower_bound(A.begin(), A.end(), B[idx]);
        A.insert(pos, B[idx]);
    }
    
    container.swap(A);
}

void fordAlgorithmList(std::list<int> &container) {
    size_t n = container.size();

    if (n <= 1) return;
}

void print_deque(std::deque<int> &container, std::string step) {
    std::cout << step;
    for (size_t it = 0; it < container.size(); ++it) {
        std::cout << container[it] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::deque_sort(std::deque<int> &container)
{
    print_deque(container, "Before: ");

    struct timeval deque_start, deque_end;
    gettimeofday(&deque_start, NULL);
    ford_algorithm_deque(container);
    gettimeofday(&deque_end, NULL);

    /* struct timeval list_start, list_end;
    gettimeofday(&list_start, NULL);
    ford_algorithm(this->list_container);
    gettimeofday(&list_end, NULL); */

    print_deque(container, "After: ");

    long deque_seconds = deque_end.tv_sec - deque_start.tv_sec;
    long deque_usec = deque_seconds * 1000000 + (deque_end.tv_usec - deque_start.tv_usec);
    std::cout << "Time to process a range of " << container.size() <<
    " elements with std::deque: " << deque_usec << " us" << std::endl;

    /* long list_seconds = list_end.tv_sec - list_start.tv_sec;
    long list_usec = list_seconds * 1000000 + (list_end.tv_usec - list_start.tv_usec);
    std::cout << "Time to process a range of " << list_container.size() <<
    " elements with std::list :" << list_usec << " us" << std::endl; */
}


