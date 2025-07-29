/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:49:43 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/29 14:11:48 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name( "" ), _grade( 1 ) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name( other.getName() )
{
	this->_grade = other.getGrade();
	return ;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if ( this != &other)
		this->_grade = other.getGrade();

	return *this;
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat( std::string name, int grade): _name( name )
{
	if (grade > 150) throw GradeTooLowException();
	if (grade < 0) throw GradeTooHigthException();
	this->_grade = grade;
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if ((this->getGrade() - 1) < 1) throw GradeTooHigthException();
	this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if ((this->getGrade() + 1) > 150) throw GradeTooLowException();
	this->_grade++;
}
void Bureaucrat::signForm( AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn’t sign " << form.getName()
		<< " because ";
		std::cerr << e.what() << '\n';
	}

}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}


const char* Bureaucrat::GradeTooHigthException::what() const throw()
{
	return "GradeTooHighException";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &value)
{
	out << value.getName() << " , bureaucrat grade " << value.getGrade() << ".";
    return out;
}