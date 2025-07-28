/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:14:45 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/28 14:31:46 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	try
	{
		std::cout << "CREATE/INCREMENT/DECREMENT" << std::endl;
		Bureaucrat alice("Alice", 150);
		std::cout << alice << std::endl;
		std::cout << std::endl;
		std::cout << "Incrementing\n";
		alice.incrementGrade();
		std::cout << alice << std::endl;
		std::cout << std::endl;
		std::cout << "Decrementing\n";
		alice.decrementGrade();
		std::cout << alice << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Alice: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "TOO LOW EXECPETION" << std::endl;
		Bureaucrat bob("Bob", -1);
	}
	catch (std::exception &e)
	{
		std::cerr << "Bob: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "TOO HIGHT EXECPETION" << std::endl;
		Bureaucrat charlie("Charlie", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << "Charlie: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "TOO HIGHT EXECPETION" << std::endl;
		Bureaucrat elite("Elite", 1);
		elite.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Elite: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "TOO LOW EXECPETION" << std::endl;
		Bureaucrat intern("Intern", 150);
		intern.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Intern: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Copy Constructor Test ---\n";
		Bureaucrat original("Original", 50);
		std::cout << "Original: " << original << std::endl;
		Bureaucrat copy(original); // Copy constructor
		std::cout << "Copy:     " << copy << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Copy constructor exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n--- Assignment Operator Test ---\n";
		Bureaucrat a("Alpha", 60);
		Bureaucrat b("Beta", 30);
		std::cout << "Before assignment:\n";
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		a = b;
		std::cout << "After assignment:\n";
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Assignment operator exception: " << e.what() << std::endl;
	}

	return (0);
}
