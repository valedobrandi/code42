#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
    
    if (argc != 2) {
        std::cerr << "usage: ./RPN \"RPN expression\"" << std::endl;
        return 1;
    }

    RPN rpn = RPN();
    std::string input = argv[1];
    try
    {
        rpn.calculate(input);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    
    return 0;
}