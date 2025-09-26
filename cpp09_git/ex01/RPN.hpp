#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>

class RPN {

    public:
        RPN(void);
        ~RPN(void);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);

        void calculate(std::stack<int> &st, std::string input);
};

#endif