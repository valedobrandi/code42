/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:42:54 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/29 13:02:38 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_H
# define BUREAUCRAT_CLASS_H
#include <iostream>

class Bureaucrat
{
	private:

		const std::string _name;
		int _grade;

	public:

		Bureaucrat( void );
        Bureaucrat( const Bureaucrat& other );
        Bureaucrat& operator=( const Bureaucrat& other );
        ~Bureaucrat( void );

		Bureaucrat( std::string name, int grade);

		std::string getName() const;
		int getGrade() const;

		void incrementGrade( void );
		void decrementGrade( void );

		class GradeTooHigthException: public std::exception
		{
			virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			virtual const char* what() const throw();
		};

};

	std::ostream& operator<<(std::ostream& out, const Bureaucrat& value);

#endif