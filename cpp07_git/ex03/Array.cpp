/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:26:05 by bde-albu          #+#    #+#             */
/*   Updated: 2025/08/07 14:09:38 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void)
{
	this->_data = new T[];
	this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_data = new T[n];
	this->_size = n;
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] this->_data;
}

template <typename T>
Array<T>::Array(const Array &other)
{
	this->_size = other._size;
	delete[] this->_data;
	if ( other._size > 0)
	{
		this->_data = new T[other._size]
		for (size_t i = 0; i < )

	}
	else
		this->_data = new T[];
}

template <typename T>
Array &Array<T>::operator=(const Array &other)
{
	// TODO: insert return statement here
}
