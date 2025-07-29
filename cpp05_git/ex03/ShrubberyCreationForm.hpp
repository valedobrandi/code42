/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:40:43 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/29 14:03:43 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFROM_CLASS_H
# define SHRUBBERYCREATIONFROM_CLASS_H

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:

		std::string _target;

	public:

		ShrubberyCreationForm( void );
        ShrubberyCreationForm( const ShrubberyCreationForm& other );
        ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other );
        ~ShrubberyCreationForm( void );

		ShrubberyCreationForm( const std::string& target );

		virtual void execute(Bureaucrat const & executor) const;

};

#endif