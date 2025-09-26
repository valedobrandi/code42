#include "PmergeMe.hpp"
#include <algorithm>
#include <sys/time.h>
#include <iterator>


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


std::deque<int> jacobIndex(int n) {
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

void fordAlgorithmDeque(std::deque<int> &container) {
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

    fordAlgorithmDeque(A);

    std::deque<int> jacob_seq = jacobIndex(B.size());

    for (dequeIntIt it = jacob_seq.begin(); it != jacob_seq.end(); ++it) {
        int idx = *it;
        dequeIntIt pos = std::lower_bound(A.begin(), A.end(), B[idx]);
        A.insert(pos, B[idx]);
    }

    container.swap(A);
}

long long  PmergeMe::dequeSort(std::deque<int> &container)
{
	struct timeval start, end;
    gettimeofday(&start, NULL);
    fordAlgorithmDeque(container);
    gettimeofday(&end, NULL);

	long sec = end.tv_sec - start.tv_sec;
    long usec = end.tv_usec - start.tv_usec;
	if (usec < 0) { sec--; usec += 1000000;};
    return sec * 1000000LL + usec;

}

template <typename T>
typename std::list<T>::iterator binarInsert(std::list<T> &lst, const T& value) {
	listIntIt first = lst.begin();
	listIntIt last = lst.end();
	int len = std::distance(first, last);
	while (len > 0) {
		listIntIt mid = first;
		int half = len / 2;
		std::advance(mid, half);
		if (*mid < value) {
			first = ++mid;
			len -= half+1;
		} else {
			len = half;
		}
	}
	return first;
}

void fordAlgorithmList(std::list<int> &container) {
    size_t n = container.size();

    if (n <= 1) return;

	std::list<int> A, B;
	listIntIt it = container.begin();
	while ( it != container.end()) {
		listIntIt nextIt = it;
		++nextIt;
		if (nextIt == container.end()) break;
		if (*it > *nextIt) {
			A.push_back(*it);
			B.push_back(*nextIt);
		} else {
			A.push_back(*nextIt);
			B.push_back(*it);
		}
		++it;
    	++it;
	}
	if (it != container.end()) {
		A.push_back(*it);
	}
	fordAlgorithmList(A);
	container.clear();
	std::deque<int> jacobSeq = jacobIndex(B.size());
	for (dequeIntIt it = jacobSeq.begin(); it != jacobSeq.end(); ++it) {
        listIntIt idx = B.begin();
		std::advance(idx, *it);
        listIntIt pos = binarInsert(A, *idx);
        A.insert(pos, *idx);
    }
	container.splice(container.begin(), A);
}


long long  PmergeMe::listSort(std::list<int> &container)
{
	struct timeval start, end;
    gettimeofday(&start, NULL);
    fordAlgorithmList(container);
    gettimeofday(&end, NULL);

	long sec = end.tv_sec - start.tv_sec;
    long usec = end.tv_usec - start.tv_usec;
	if (usec < 0) { sec--; usec += 1000000;};
    return sec * 1000000LL + usec;
}

