/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:14:45 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/29 15:16:51 by bde-albu         ###   ########.fr       */
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
		std::cout << "---> ShrubberyCreationForm Bob Test" << std::endl;
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
		std::cout << "---> ShrubberyCreationForm Alice Test" << std::endl;
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
		std::cout << "---> ShrubberyCreationForm Kenny Test" << std::endl;
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
		std::cout << "---> RobotomyRequestForm Bob Test" << std::endl;
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
		std::cout << "---> RobotomyRequestForm Alice Test" << std::endl;
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
		std::cout << "\033[32m---> RobotomyRequestForm Kenny Test\033[0m" << std::endl;
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
		std::cout << "---> PresidentialPardonForm Bob Test" << std::endl;
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
		std::cout << "---> PresidentialPardonForm Alice Test" << std::endl;
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
		std::cout << "\033[32m---> PresidentialPardonForm Kenny Test\033[0m" << std::endl;
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
