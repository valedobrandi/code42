/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:52:09 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/08 10:52:10 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H
#include <string>

class Zombie {

    private:

        std::string name;

    public:

    Zombie( void );
    ~Zombie( void );

    void announce( void );
	void setName( std::string name );
};

Zombie* zombieHorde( int N, std::string name );

#endif