/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:23:15 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/29 14:43:34 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name(""), _isSigned(0), _requiredSign(0), _requiredExecute(0)
{
}

AForm::AForm(const AForm &other)
	:_requiredSign( getRequireSing() ),
	 _requiredExecute( getRequireExecute() )
{
	this->_isSigned = other.getIsSigned();
	return ;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_isSigned = other.getIsSigned();
	return (*this);
}

AForm::~AForm(void)
{
}

AForm::AForm(std::string name, int signGrade, int executeGrade) : _name(name),
	_isSigned(false), _requiredSign(validateGrade(signGrade)),
	_requiredExecute(validateGrade(executeGrade))
{
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

int AForm::getRequireSing() const
{
	return (this->_requiredSign);
}

int AForm::getRequireExecute() const
{
	return (this->_requiredExecute);
}

void AForm::beSigned(Bureaucrat &t)
{
	if (t.getGrade() > this->getRequireSing())
		throw GradeTooLowException();
	this->_isSigned = true;
}

int AForm::validateGrade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHigthException();
	return (grade);
}

const char* AForm::GradeTooHigthException::what() const throw()
{
	return "GradeTooHighException: Grade too higth";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException: Grade too low.";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "FormNotSignedException: Form not signed.";
}

std::ostream &operator<<(std::ostream &out, const AForm &value)
{
	out << "name: " << value.getName()
	<< ", signed: " << value.getIsSigned()
	<< ", require grade to sign: " << value.getRequireSing()
	<< ", require grade to execute: " << value.getRequireExecute();
	return out;
}
