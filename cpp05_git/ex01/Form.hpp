/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:42:54 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/28 15:23:36 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_H
# define FORM_CLASS_H

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:

		const std::string _name;
		bool _isSigned;
		const int _requireSing;
		const int _requireExecute;

	public:

		Form( void );
        Form( const Form& other );
        Form& operator=( const Form& other );
        ~Form( void );

		Form( std::string name, int signGrade, int executeGrade);

		std::string getName() const;
		bool getIsSigned( void ) const;
		int getRequireSing( void ) const;
		int getRequireExecute( void ) const;

		void beSigned( Bureaucrat& );

		class GradeToohigthException: public std::exception
		{
			virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			virtual const char* what() const throw();
		};

		static int validateGrade( int grade );
};

	std::ostream& operator<<(std::ostream& out, const Form& value);

#endif