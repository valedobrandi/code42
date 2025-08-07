/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:26:03 by bde-albu          #+#    #+#             */
/*   Updated: 2025/08/07 14:07:04 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_CLASS_HPP
# define ARRAY_CLASS_HPP

# include <cstddef>

template <typename T> class Array
{
  private:
	T *_data;
	int _size;

  public:
	Array(void);
	~Array(void);
	Array( const Array& other);
	Array& operator=( const Array& other);

	Array(unsigned int n);
};

#endif