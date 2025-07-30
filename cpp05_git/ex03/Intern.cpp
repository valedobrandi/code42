/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:25:59 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/30 13:17:56 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern& /* other */)
{

}

Intern &Intern::operator=(const Intern& /* other */)
{
	return *this;
}

Intern::~Intern(void) {}

AForm* Intern::makeForm(std::string name, std::string target)
{
	const std::string request[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	CreateFormFunc form[3] = {&Intern::robotomy, &Intern::presidential, &Intern::shrubbery};
	for (int i = 0; i < 3; i++ )
	{
		if (name == request[i])
		{
			std::cerr << "Intern creates " << request[i] << std::endl;
			return ((this->*form[i])(target));
		}
	}

	throw std::invalid_argument("Unknown form name: " + name);

	return NULL;

}

AForm* Intern::robotomy(const std::string &target) const
{
	return new RobotomyRequestForm(target);;
}

AForm* Intern::presidential(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::shrubbery(const std::string &target) const
{
	return new ShrubberyCreationForm(target);
}
