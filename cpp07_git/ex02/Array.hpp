/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:26:03 by bde-albu          #+#    #+#             */
/*   Updated: 2025/09/17 09:38:24 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_CLASS_HPP
# define ARRAY_CLASS_HPP

#include <cstddef>
#include <exception>
#include <ostream>

template <typename T> class Array
{
  private:
	T *_data;
	size_t _size;

  public:
	Array(void);
	Array(size_t n);
	~Array(void);
	Array( const Array& other);
	Array<T>& operator=( const Array<T>& other);


	const T& operator[](size_t i) const;
	T& operator[](size_t i);

	size_t size() const;

};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T>& arr);

#include "Array.tpp"
#endif