/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:25:59 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/29 15:33:44 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &other) {}

Intern &Intern::operator=(const Intern &other)
{
	return *this;
}

Intern::~Intern(void) {}

AForm* Intern::makeForm(std::string name, std::string target)
{
	char *forms[] = {"robotomy request", "robotomy request", "robotomy request", "robotomy request"};

	switch (name)
	{
	case "robotomy reques"t:
		/* code */
		break;

	default:
		break;
	}
}
