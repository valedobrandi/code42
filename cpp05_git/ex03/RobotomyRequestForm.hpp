/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:40:43 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/29 14:52:27 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_CLASS_H
# define ROBOTOMYREQUESTFORM_CLASS_H

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:

		std::string _target;

	public:

		RobotomyRequestForm( void );
        RobotomyRequestForm( const RobotomyRequestForm& other );
        RobotomyRequestForm& operator=( const RobotomyRequestForm& other );
        ~RobotomyRequestForm( void );

		RobotomyRequestForm( const std::string& target );

		virtual void execute(Bureaucrat const & executor) const;

};

#endif