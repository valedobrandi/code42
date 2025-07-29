/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:50:58 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/29 15:04:01 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequestForm", 72, 45), _target( "" )
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm( other ), _target( other._target ) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=( other );
		_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

RobotomyRequestForm::RobotomyRequestForm( const std::string& target )
	: AForm("RobotomyRequestForm", 72, 45), _target( target ) {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
	{
		std::cout << "Signed error: robotomy failed. ";
		throw AForm::FormNotSignedException();
	}
	if ( executor.getGrade() > getRequireExecute())
	{
		std::cout << "Execute error: robotomy failed. ";
		throw AForm::GradeTooLowException();
	}

	std::cout << "vrumrumvrumvrum! " << executor.getName()
		<< " has been robotomized successfully 50% of the time." << std::endl;
}
