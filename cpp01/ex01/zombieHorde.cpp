/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:22:50 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/08 10:54:47 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	if (N <= 0)
		return NULL;
	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		horde[i].setName( name );
	}

	return horde;
}
