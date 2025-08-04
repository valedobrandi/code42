/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:39:03 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/30 14:27:19 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
#include <iostream>
#include <cfloat>
#include <string>
#include <cmath>
#include <iomanip>

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter & /* other */)
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter & /* other */)
{
    return *this;
}

ScalarConverter::~ScalarConverter(void)
{
}

bool isPrintableChar(char c)
{
    return c >= 32 && c <= 126;
}

bool tryParseInt(const std::string &s, int &out)
{
    std::stringstream ss(s);
    ss >> out;
    return !ss.fail() && ss.eof();
}

bool tryParseDouble(std::string &s, double &out)
{
    std::stringstream ss(s);
    ss >> out;
    return !ss.fail() && ss.eof();
}

void print(char c, int i, float f, double d)
{
    std::cout << std::setprecision(1) << std::fixed;

    if (isPrintableChar(c))
        std::cout << "char: '" << c << "'"<< std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << i << std::endl;

    if (isnan(f))
        std::cout << "float: nanf" << std::endl;
    else if (isinf(f))
        std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    
    if (isnan(d))
        std::cout << "double: nanf" << std::endl;
    else if (isinf(d))
        std::cout << "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
    else
        std::cout << "double: " << d << std::endl;

}

void ScalarConverter::convert(const std::string &input)
{
    if (input.length() == 1 && !std::isdigit(input[0]))
    {
        char c = input[0];
        int i = static_cast<int>(c);
        float f = static_cast<float>(c);
        double d = static_cast<double>(c);

        print(c, i, f, d);
    }
    else
    {
        int i;
        if (tryParseInt(input, i))
        {
            char c = static_cast<char>(i);
            float f = static_cast<float>(i);
            double d = static_cast<double>(i);

            print(c, i, f, d);
        }
        else
        {
            std::string fout = input;
            int length = input.size();
            if (length > 1 && input[length - 1] == 'f')
                fout = input.substr(0, input.size() - 1);
            double d;
            if (tryParseDouble(fout, d))
            {
                int i = static_cast<char>(d);
                char c = static_cast<char>(i);
                float f = static_cast<float>(d);

                print(c, i, f, d);
            }
            else
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;

                if (input == "nanf" || input == "nan")
                {
                    std::cout << "float: nanf" << std::endl;
                    std::cout << "double: nan" << std::endl;
                }
                else if (input == "+inff" || input == "+inf")
                {
                    std::cout << "float: +inff" << std::endl;
                    std::cout << "double: +inf" << std::endl;
                }
                else if (input == "-inff" || input == "-inf")
                {
                    std::cout << "float: -inff" << std::endl;
                    std::cout << "double: -inf" << std::endl;
                }
            }
        }
    }

    return;
}
