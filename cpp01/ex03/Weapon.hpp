/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:43:13 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/08 12:45:46 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_CLASS_H
#define WEAPON_CLASS_H
#include <iostream>

class Weapon {

	public:

		Weapon( std::string );
		~Weapon( void );

		std::string getType( void ) const;
		void setType( std::string );

	private:

		std::string type;

};

#endif