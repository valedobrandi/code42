/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:42:54 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/29 14:38:34 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_CLASS_H
# define AFORM_CLASS_H

# include <iostream>

class	Bureaucrat;

class AForm
{
  private:

	const std::string _name;
	bool _isSigned;
	const int _requiredSign;
	const int _requiredExecute;



  public:
	AForm(void);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm(void);

	AForm(std::string name, int signGrade, int executeGrade);

	std::string getName() const;
	bool getIsSigned(void) const;
	int getRequireSing(void) const;
	int getRequireExecute(void) const;

	void beSigned(Bureaucrat &t);
	virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHigthException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	static int validateGrade(int grade);
};

std::ostream &operator<<(std::ostream &out, const AForm &value);

#endif