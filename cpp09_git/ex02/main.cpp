#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: bad input" << std::endl;
        return 1;
    }

    PmergeMe deque;
    try
    {
        deque.deque_sort(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
    
}