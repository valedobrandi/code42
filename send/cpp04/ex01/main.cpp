/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:52:02 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/22 09:14:57 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <ostream>
#include <iostream>

int main(void)
{
    {
		std::cout << std::endl;
        std::cout << "=== PDF TEST ===" << std::endl;
        const Animal *j = new Dog();
        const Animal *i = new Cat();
        delete j;
        delete i;
    }

    {
		std::cout << std::endl;
        std::cout << "=== MAIN TEST ===" << std::endl;
        Animal* t[100];

        for (int i = 0; i < 50; i++)
            t[i] = new Cat;
        for (int i = 50; i < 100; i++)
            t[i] = new Dog;

        for (int i = 0; i < 100; i++)
            delete t[i];

    }

    return 0;
}
