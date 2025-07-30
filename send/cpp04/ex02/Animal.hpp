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

#ifndef ANIMAL_CLASS_H
# define ANIMAL_CLASS_H
#include <iostream>

class Animal {

    protected:

        std::string type;

    public:

        Animal( void );
        Animal( const Animal& other );
        Animal& operator=( const Animal& rhs );
        virtual ~Animal( void );

        std::string getType( void ) const;
        virtual void makeSound( void ) const = 0;
};


#endif