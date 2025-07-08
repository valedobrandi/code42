/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:52:02 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/08 10:53:20 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {
    int n = 5;

	Zombie* horde = zombieHorde( n, "THEHORDE" );

	horde[0].announce();
	horde[1].announce();
	horde[2].announce();
	horde[3].announce();
	horde[4].announce();

	delete[] horde;

    return 0;
}

