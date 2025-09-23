#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>

class RPN {

    public:
        std::stack<int> st;

        RPN(void);
        ~RPN(void);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);

        void calculate(std::string input);
};

#endif