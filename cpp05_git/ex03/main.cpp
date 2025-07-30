/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:14:45 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/30 13:18:23 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

void	shrubberyCreationForm(void)
{
	Bureaucrat kenny("Kenny", 1);
	Intern someRandomIntern;
	AForm *form;

	try
	{
		std::cout << "\033[32m---> shrubberyCreationForm Test\033[0m" << std::endl;
		form = someRandomIntern.makeForm("shrubbery creation", "Bender");
		std::cout << kenny << std::endl;
		kenny.signForm(*form);
		std::cout << *form << std::endl;
		kenny.executeForm(*form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	delete form;
}

void	robotomyRequestForm(void)
{
	Bureaucrat kenny("Kenny", 1);
	Intern someRandomIntern;
	AForm *form;

	try
	{
		std::cout << "\033[32m---> robotomyRequestForm Test\033[0m" << std::endl;
		form = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << kenny << std::endl;
		kenny.signForm(*form);
		std::cout << *form << std::endl;
		kenny.executeForm(*form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	delete form;

}

void	presidentialPardonForm(void)
{
	Bureaucrat kenny("Kenny", 1);
	Intern someRandomIntern;
	AForm *form;

	try
	{
		std::cout << "\033[32m---> presidentialPardonForm Test\033[0m" << std::endl;
		form = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << kenny << std::endl;
		kenny.signForm(*form);
		std::cout << *form << std::endl;
		kenny.executeForm(*form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	delete form;
}

void	noFormForm(void)
{
	Bureaucrat kenny("Kenny", 1);
	Intern someRandomIntern;

	try
	{
		std::cout << "\033[32m---> noFormForm Test\033[0m" << std::endl;
		AForm *form = someRandomIntern.makeForm("noForm request", "Bender");
		std::cout << kenny << std::endl;
		kenny.signForm(*form);
		std::cout << *form << std::endl;
		kenny.executeForm(*form);
		delete form;
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
	std::cout << std::endl;
	noFormForm();
	return (0);
}
