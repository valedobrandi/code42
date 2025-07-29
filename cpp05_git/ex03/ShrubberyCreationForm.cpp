/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:50:58 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/29 15:12:36 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137), _target( "" )
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm( other ), _target( other._target ) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=( other );
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target )
	: AForm("ShrubberyCreationForm", 145, 137), _target( target ) {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
	{
		std::cout << "Signed error: not tree. ";
		throw AForm::FormNotSignedException();
	}
	if ( executor.getGrade() > getRequireExecute())
	{
		std::cout << "Execute error: no tree. ";
		throw AForm::GradeTooLowException();
	}
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open())
		throw std::ios::failure("Failed to open file");

	file <<
	"       _-_\n"
	"    /~~   ~~\\\n"
	" /~~         ~~\\\n"
	"{               }\n"
	" \\  _-     -_  /\n"
	"   ~  \\\\ //  ~\n"
	"_- -   | | _- _\n"
	"  _ -  | |   -_\n"
	"      // \\\\\n";

	file.close();

}
