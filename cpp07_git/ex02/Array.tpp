/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:26:05 by bde-albu          #+#    #+#             */
/*   Updated: 2025/09/17 09:39:15 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array(void)
{
	this->_data = NULL;
	this->_size = 0;
}

template <typename T>
Array<T>::Array(size_t n)
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
Array<T>::Array(const Array &other) : _size(other._size)
{
	if ( this->_size > 0)
	{
		this->_data = new T[other._size];
		for (size_t i = 0; i < other._size; ++i) {
			this->_data[i] = other._data[i];
		}
	}
	else
		this->_data = NULL;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this == &other) return *this;

	delete[] this->_data;

	this->_size = other._size;

	if ( other._size > 0)
	{
		this->_data = new T[other._size];
		for (size_t i = 0; i < this->_size; ++i) {
			this->_data[i] = other._data[i];
		}

	}
	else
		this->_data = NULL;
	return *this;
}


template<typename T>
const T& Array<T>::operator[](size_t i) const {

	if (i < 0 || i >= this->_size ) {
		throw std::out_of_range("Index out of bounds");
	}

	return this->_data[i];
}

template<typename T>
T& Array<T>::operator[](size_t i) {

	if (i < 0 || i >= this->_size ) {
		throw std::out_of_range("Index out of bounds");
	}

	return this->_data[i];
}

template<class T>
size_t Array<T>::size() const {
	return this->_size;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T>& arr) {
	os << "Size []: " << arr.size() << std::endl;
	for (size_t it = 0; it < arr.size(); ++it)
		os << arr[it] << " ";
	return os;
}