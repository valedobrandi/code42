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

#ifndef WRONGCAT_CLASS_H
# define WRONGCAT_CLASS_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
    public:

    WrongCat( void );
    WrongCat( const WrongCat& other );
    WrongCat& operator=( const WrongCat& rhs );
    ~WrongCat( void );

    void makeSound( void ) const;
};


#endif