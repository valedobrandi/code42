/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:49:22 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/08 12:53:07 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_CLASS_H
#define HUMAN_B_CLASS_H

#include <iostream>
#include "Weapon.hpp"

class HumanB {

    private:

        std::string name;
		Weapon* weapon;

	public:

		HumanB( std::string name );
		~HumanB( void );

        void attack( void ) const;
        void setWeapon( Weapon& weapon );
};

#endif