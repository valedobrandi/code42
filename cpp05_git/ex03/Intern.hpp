/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:42:54 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/29 15:27:04 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_H
# define INTERN_CLASS_H

# include <iostream>
# include "AForm.hpp"

class Intern {

	public:

		Intern( void );
		Intern( const Intern& other );
		Intern& operator=( const Intern& other );
		~Intern( void );

		AForm* makeForm(std::string name, std::string target);

};

#endif