/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:40:43 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/29 15:09:33 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_CLASS_H
# define PRESIDENTIALPARDONFORM_CLASS_H

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:

		std::string _target;

	public:

		PresidentialPardonForm( void );
        PresidentialPardonForm( const PresidentialPardonForm& other );
        PresidentialPardonForm& operator=( const PresidentialPardonForm& other );
        ~PresidentialPardonForm( void );

		PresidentialPardonForm( const std::string& target );

		virtual void execute(Bureaucrat const & executor) const;

};

#endif