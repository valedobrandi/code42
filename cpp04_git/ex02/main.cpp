/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:52:02 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/08 10:53:20 by bde-albu         ###   ########.fr       */
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
        const Animal *j = new Dog();
        const Animal *i = new Cat();
        delete j; 
        delete i;
    }

    {
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
