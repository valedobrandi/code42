#include "RPN.hpp"
#include <stdexcept>

RPN::RPN(void)
{
}

RPN::~RPN(void)
{
}

RPN::RPN(const RPN &/* other */)
{
}

RPN &RPN::operator=(const RPN &/* other */)
{
    return *this;
}

void RPN::calculate(std::stack<int> &st, std::string input)
{
    int quantity_of_numbers = 0;
    int res = 0;
    for (size_t i = 0; i < input.size(); ++i) {
        char c = input[i];
        if (c == ' ') continue;
        if (c >= '0' && c <= '9') {
            st.push(c - '0');
            quantity_of_numbers++;
            if (quantity_of_numbers > 10) {
                throw std::runtime_error("Error: more than 10 numbers");
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (st.size() < 2) {
                throw std::runtime_error("Error: not enough operators");
            }
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            if (c == '+') res = a + b;
            else if (c == '-') res = a - b;
            else if (c == '*') res = a * b;
            else if (c == '/') {
                if (b == 0) {
                    throw std::runtime_error("Error: division by 0");
                }
                res = a / b;
            }
            st.push(res);
        } else {
            throw std::runtime_error("Error: not a valid character");
        }
    }
    if (st.size() != 1) {
        throw std::runtime_error("Error: invalid RPN expression");
    }
    std::cout << res << std::endl;
    st.pop();
}
