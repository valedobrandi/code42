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

#include <iostream>

class Weapon {

	public:

		Weapon( void );
		~Weapon( void );

		std::string getType( void ) const;
		void setType( std::string ) const;

	private:

		std::string type;

};