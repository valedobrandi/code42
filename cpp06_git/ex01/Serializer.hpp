/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:32:23 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/30 13:48:20 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_CLASS_H
# define SERIALIZER_CLASS_H

#include <iostream>
#include <stdint.h>
#include "data.hpp" 

class Serializer
{
    private:

        Serializer( void );

	public:

        Serializer( const Serializer& other );
        Serializer& operator=( const Serializer& other );
        ~Serializer( void );

		static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif