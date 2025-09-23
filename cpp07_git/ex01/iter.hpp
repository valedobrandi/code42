/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:21:13 by bde-albu          #+#    #+#             */
/*   Updated: 2025/09/17 09:07:10 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>


template <typename T>
void iter(T *array, size_t size, void (*func)( T& ))
{
    for (size_t t = 0; t < size; t++)
        func(array[t]);
}

template <typename T>
void iter(const T *array, size_t size, void (*func)( const T& ))
{
    for (size_t t = 0; t < size; t++)
        func(array[t]);
}

#endif


