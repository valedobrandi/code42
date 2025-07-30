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

void ScalarConverter::convert(const std::string &input)
{
	double d = 0.0;
	float f = 0.0f;
	int i = 0;
	char c = 0;

	if (input.size() > 1 && input[input.size() - 1] == 'f')
	{
		bool parseFloat = true;
		std::string floatPart = input.substr(0, input.size() - 1);

		std::stringstream ss(floatPart);
		ss >> f;

		if (ss.fail())
		{
			std::cout << "float: impossible" << std::endl;
		}

		d = static_cast<double>(f);
		i = static_cast<int>(f);
		c = static_cast<char>(i);


	}
}