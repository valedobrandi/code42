#include "PmergeMe.hpp"
#include <climits>
#include <cstdlib>


int main(int argc, char **argv) {
    if (argc < 1) {
        std::cerr << "Error: bad input" << std::endl;
        return 1;
    }

    std::deque<int> dequeContainer;

    for (int i = 1; i < argc; ++i) {
        int index = 0;
        while (argv[i][index]) {
            if (std::isdigit(argv[i][index]) == false) {
                std::cerr << "Error: " << argv[i][index] << std::endl;
                return 1;
            }
            index++;

        }
        long value = atol(argv[i]);
        if (value < 0 || value > INT_MAX) {
            std::cerr << "Error: " << value << std::endl;
            return 1;
        }
        dequeContainer.push_back(value);
    }
	std::list<int> listContainer(dequeContainer.begin(), dequeContainer.end());
	size_t size = dequeContainer.size();

    try
    {
        PmergeMe mergeInsert;

		long long totalDeque = 0, totalList = 0;

		totalDeque = mergeInsert.dequeSort(dequeContainer);
		totalList = mergeInsert.listSort(listContainer);

		std::cout << "Time to process a range of " << size <<
		" elements with std::deque :" << totalDeque << " us" << std::endl;

		std::cout << "Time to process a range of " << size <<
		" elements with std::list :" << totalList << " us" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;

}