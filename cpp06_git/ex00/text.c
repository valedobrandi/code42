#include <iostream>
#include <string>
#include <sstream>
#include <cctype> // for isprint

bool isPrintableChar(char c) {
    return c >= 32 && c <= 126;
}

bool tryParseInt(const std::string& s, int& out) {
    std::stringstream ss(s);
    ss >> out;
    return !ss.fail() && ss.eof();
}

bool tryParseDouble(const std::string& s, double& out) {
    std::stringstream ss(s);
    ss >> out;
    return !ss.fail() && ss.eof();
}

int main() {
    std::string input;
    std::cout << "Enter a literal: ";
    std::cin >> input;

    // If input length 1 and not digit, treat as char
    if (input.length() == 1 && !std::isdigit(input[0])) {
        char c = input[0];
        int i = static_cast<int>(c);
        float f = static_cast<float>(i);
        double d = static_cast<double>(i);

        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << i << "\n";
        std::cout << "float: " << f << "f\n";
        std::cout << "double: " << d << "\n";
    } else {
        // Try int
        int i;
        if (tryParseInt(input, i)) {
            char c = static_cast<char>(i);
            float f = static_cast<float>(i);
            double d = static_cast<double>(i);

            std::cout << "char: " << (isPrintableChar(c) ? std::string("'") + c + "'" : "Non displayable") << "\n";
            std::cout << "int: " << i << "\n";
            std::cout << "float: " << f << "f\n";
            std::cout << "double: " << d << "\n";
        } else {
            // Try double (including float literals with 'f' suffix)
            bool isFloatLiteral = false;
            if (input.size() > 1 && input.back() == 'f') {
                isFloatLiteral = true;
                input = input.substr(0, input.size() -1);
            }
            double d;
            if (tryParseDouble(input, d)) {
                int i = static_cast<int>(d);
                char c = static_cast<char>(i);
                float f = static_cast<float>(d);

                std::cout << "char: " << (isPrintableChar(c) ? std::string("'") + c + "'" : "Non displayable") << "\n";
                std::cout << "int: " << i << "\n";
                std::cout << "float: " << f << "f\n";
                std::cout << "double: " << d << "\n";
            } else {
                std::cout << "Invalid input\n";
            }
        }
    }

    return 0;
}