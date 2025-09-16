#include "ScalarConverter.hpp"

int main() {
    ScalarConverter::convert("42");
    ScalarConverter::convert("'A'");
    ScalarConverter::convert("4.2f");
    ScalarConverter::convert("nan");
    ScalarConverter::convert("+inff");

    ScalarConverter::convert("0");
    ScalarConverter::convert("-42");
    ScalarConverter::convert("2147483647");
    ScalarConverter::convert("-2147483648");
    ScalarConverter::convert("+inff");
}