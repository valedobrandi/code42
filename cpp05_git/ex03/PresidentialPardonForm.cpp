/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:50:58 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/29 15:11:57 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("PresidentialPardonForm", 25, 5), _target( "" )
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm( other ), _target( other._target ) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=( other );
		_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

PresidentialPardonForm::PresidentialPardonForm( const std::string& target )
	: AForm("PresidentialPardonForm", 25, 5), _target( target ) {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
	{
		std::cout << "Signed error: pardoned fail. ";
		throw AForm::FormNotSignedException();
	}
	if ( executor.getGrade() > getRequireExecute())
	{
		std::cout << "Execute error: pardoned fail. ";
		throw AForm::GradeTooLowException();
	}

	std::cout << executor.getName()
		<< " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
