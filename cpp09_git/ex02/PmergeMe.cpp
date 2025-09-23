#include "PmergeMe.hpp"
#include <sstream>
#include <climits>
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

bool is_digit(std::string number) {
    for (size_t i = 0; i < number.size(); ++i) {
        if (isdigit(number[i]) == false) return false;
    }
    return true;
}

std::deque<size_t> jacobs_index(size_t n) {
    std::deque<size_t> index;
    size_t j0 = 0, j1 = 1;
    while (j1 < n) {
        seq.push_back(j1);
        size_t next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;
    }
    return seq;
}

void ford_algorithm(std::deque<int> &container) {
    std::deque<int> A;
    std::deque<int> B;
    size_t i = 0;
    if (container.size() <= 2) return;
    while (i+1 < container.size()) {
        if (container[i] > container[i+1]) {
            A.push_back(container[i]);
            B.push_back(container[i+1]);
        } else {
            A.push_back(container[i+1]);
            B.push_back(container[i]);
        }
        i+= 2;
    }

    int leftover = -1;
    if (container.size() % 2 != 0) {
        leftover = container.back();
    }

    ford_algorithm(A);

    std::deque<size_t> jacob_seq = jacobs_index(B.size());

    std::deque<bool> used(B.size(), false);
    used[0] = true;

    // Insert losers in Jacobsthal order
    for (size_t idx : order) {
        if (idx < B.size() && !used[idx]) {
            auto pos = std::lower_bound(A.begin(), A.end(), B[idx]);
            A.insert(pos, B[idx]);
            used[idx] = true;
        }
    }

    // Insert remaining ones (not covered by Jacobsthal)
    for (size_t t = 0; t < B.size(); ++t) {
        if (!used[t]) {
            auto pos = std::lower_bound(A.begin(), A.end(), B[t]);
            A.insert(pos, B[t]);
        }
    }
    // Insert remaining ones (not covered by Jacobsthal)
    for (size_t t = 0; t < B.size(); ++t) {
        if (!used[t]) {
            auto pos = std::lower_bound(A.begin(), A.end(), B[t]);
            A.insert(pos, B[t]);
        }
    }
    if (leftover != -1) {
        dequeIt pos = std::lower_bound(A.begin(), A.end(), leftover);
        A.insert(pos, leftover);
    }
    container = A;
}

void print_deque(std::deque<int> &container, std::string step) {
    std::cout << step;
    for (size_t it = 0; it < container.size(); ++it) {
        std::cout << container[it] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::deque_sort(std::string input)
{
    std::istringstream oss(input);
    std::string number;
    while (oss >> number) {
        if (is_digit(number) == false) {
            throw std::runtime_error("Error: not a number");
        }
        long convert = atol(number.c_str());
        if (convert < 0 || convert > INT_MAX) {
            throw std::runtime_error("Error: must be a positive integer number");
        }
        deque_container.push_back(convert);
        list_container.push_back(convert);
    }
    print_deque(deque_container, "Before: ");

    struct timeval deque_start, deque_end;
    gettimeofday(&deque_start, NULL);
    ford_algorithm(this->deque_container);
    gettimeofday(&deque_end, NULL);

    struct timeval list_start, list_end;
    gettimeofday(&list_start, NULL);
    ford_algorithm(this->list_container);
    gettimeofday(&list_end, NULL);

    print_deque(deque_container, "After: ");

    long deque_seconds = deque_end.tv_sec - deque_start.tv_sec;
    long deque_usec = deque_seconds * 1000000 + (deque_end.tv_usec - deque_start.tv_usec);
    std::cout << "Time to process a range of " << deque_container.size() <<
    " elements with std::deque :" << deque_usec << " us" << std::endl;

    long list_seconds = list_end.tv_sec - list_start.tv_sec;
    long list_usec = list_seconds * 1000000 + (list_end.tv_usec - list_start.tv_usec);
    std::cout << "Time to process a range of " << list_container.size() <<
    " elements with std::list :" << list_usec << " us" << std::endl;
}


