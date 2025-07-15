/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:49:22 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/08 12:52:20 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_CLASS_H
#define HUMAN_A_CLASS_H

#include <iostream>
#include "Weapon.hpp"

class HumanA {

    private:

        std::string name;
		Weapon& weapon;

	public:


		HumanA( std::string name, Weapon& weapon);
		~HumanA( void );

        void attack( void ) const;
};

#endif