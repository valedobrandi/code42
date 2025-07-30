/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:14:45 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/30 12:57:58 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

void	shrubberyCreationForm(void)
{
	try
	{
		std::cout << "\033[32m---> ShrubberyCreationForm Bob OK/SIGN FAIL/EXECUTE\033[0m" << std::endl;

		Bureaucrat bob("Bob", 145);
		ShrubberyCreationForm form("home");
		std::cout << bob << std::endl;
		bob.signForm(form);
		std::cout << form << std::endl;
		bob.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		std::cout << "---> ShrubberyCreationForm Alice FAIL/SIGN FAIL/EXECUTE" << std::endl;
		Bureaucrat alice("Alice", 146);
		ShrubberyCreationForm form("home");
		std::cout << alice << std::endl;
		alice.signForm(form);
		std::cout << form << std::endl;
		alice.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		std::cout << "\033[32m---> ShrubberyCreationForm Kenny OK/SIGN OK/EXECUTE\033[0m" << std::endl;
		Bureaucrat kenny("Kenny", 1);
		ShrubberyCreationForm form("home");
		std::cout << kenny << std::endl;
		kenny.signForm(form);
		std::cout << form << std::endl;
		kenny.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void robotomyRequestForm()
{
try
	{
		std::cout << "\033[32m---> RobotomyRequestForm Bob OK/SIGN FAIL/EXECUTE\033[0m" << std::endl;

		Bureaucrat bob("Bob", 72);
		RobotomyRequestForm form("home");
		std::cout << bob << std::endl;
		bob.signForm(form);
		std::cout << form << std::endl;
		bob.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		std::cout << "---> RobotomyRequestForm Alice FAIL/SIGN FAIL/EXECUTE" << std::endl;
		Bureaucrat alice("Alice", 73);
		RobotomyRequestForm form("home");
		std::cout << alice << std::endl;
		alice.signForm(form);
		std::cout << form << std::endl;
		alice.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		std::cout << "\033[32m---> RobotomyRequestForm Kenny OK/SIGN OK/EXECUTE\033[0m" << std::endl;
		Bureaucrat kenny("Kenny", 1);
		RobotomyRequestForm form("home");
		std::cout << kenny << std::endl;
		kenny.signForm(form);
		std::cout << form << std::endl;
		kenny.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void presidentialPardonForm()
{
try
	{
		std::cout << "\033[32m---> PresidentialPardonForm Bob OK/SIGN FAIL/EXECUTE\033[0m" << std::endl;

		Bureaucrat bob("Bob", 25);
		PresidentialPardonForm form("home");
		std::cout << bob << std::endl;
		bob.signForm(form);
		std::cout << form << std::endl;
		bob.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		std::cout << "---> PresidentialPardonForm Alice FAIL/SIGN FAIL/EXECUTE" << std::endl;
		Bureaucrat alice("Alice", 26);
		PresidentialPardonForm form("home");
		std::cout << alice << std::endl;
		alice.signForm(form);
		std::cout << form << std::endl;
		alice.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		std::cout << "\033[32m---> PresidentialPardonForm Kenny OK/SIGN OK/EXECUTE\033[0m" << std::endl;
		Bureaucrat kenny("Kenny", 1);
		PresidentialPardonForm form("home");
		std::cout << kenny << std::endl;
		kenny.signForm(form);
		std::cout << form << std::endl;
		kenny.executeForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}



int	main(void)
{
	shrubberyCreationForm();
	std::cout << std::endl;
	robotomyRequestForm();
	std::cout << std::endl;
	presidentialPardonForm();

	return (0);
}
