#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "usage: ./RPN \"RPN expression\"" << std::endl;
        return 1;
    }

	std::stack<int> st;
    RPN rpn = RPN();
    std::string input = argv[1];
    try
    {
        rpn.calculate(st, input);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}