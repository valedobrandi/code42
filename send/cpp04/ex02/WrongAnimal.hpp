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

#ifndef WRONGANIMAL_CLASS_H
# define WRONGANIMAL_CLASS_H
#include <iostream>

class WrongAnimal {

    protected:

        std::string type;

    public:

    WrongAnimal( void );
    WrongAnimal( const WrongAnimal& other );
    WrongAnimal& operator=( const WrongAnimal& rhs );
    virtual ~WrongAnimal( void );

    std::string getType( void ) const;
    void makeSound( void ) const;
};


#endif