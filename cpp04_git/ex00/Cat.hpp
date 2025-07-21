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

#ifndef CAT_CLASS_H
# define CAT_CLASS_H

#include "Animal.hpp"

class Cat : public Animal{
    public:

    Cat( void );
    Cat( const Cat& other );
    Cat& operator=( const Cat& rhs );
    ~Cat( void );

    void makeSound( void ) const;
};


#endif