/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:52:02 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/22 09:11:56 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <ostream>
#include <iostream>

int main( void )
{
    {
        std::cout << "=== CONSTRUCTOR ===" << std::endl;
        const Animal *meta = new Animal();
        const Animal *j = new Dog();
        const Animal *i = new Cat();
        std::cout << std::endl;
        std::cout << "=== ANIMAL TEST ===" << std::endl;
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();
        std::cout << std::endl;
        std::cout << "=== DESTRUCTOR ===" << std::endl;
        delete j;
        delete i;
        delete meta;
        std::cout << std::endl;
    }

    {
        std::cout << "=== CONSTRUCTOR ===" << std::endl;
        const WrongAnimal *meta = new WrongAnimal();
        const WrongAnimal *i = new WrongCat();
        std::cout << std::endl;

        std::cout << "=== WRONGANIMAL TEST ===" << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        meta->makeSound();
		
        std::cout << std::endl;
        std::cout << "=== DESTRUCTOR ===" << std::endl;
        delete i;
        delete meta;
    }

    return 0;
}
