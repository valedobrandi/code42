/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:52:02 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/08 12:34:59 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( void ) {

	std::string msg = "HI THIS IS BRAIN";
	std::string* stringPTR = &msg;
	std::string& stringREF = msg;

	std::cout << "adress msg: " << &msg << std::endl;
	std::cout << "adress stringPTR: " << stringPTR << std::endl;
	std::cout << "adress stringREF: " << &stringREF << std::endl;

	std::cout << "value of msg: " << msg << std::endl;
	std::cout << "value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "value of stringREF: " << stringREF << std::endl;

    return 0;
}

