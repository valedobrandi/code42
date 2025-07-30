/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:42:54 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/30 13:14:34 by bde-albu         ###   ########.fr       */
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

	private:

	AForm* robotomy(const std::string& target) const;
	AForm* presidential(const std::string& target) const;
	AForm* shrubbery(const std::string& target) const;

};

typedef AForm* (Intern::*CreateFormFunc)(const std::string&) const;

#endif