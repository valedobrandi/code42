/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:42:15 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/30 13:47:15 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <stdlib.h>
#include <time.h>
#include <iostream>

Base *generate(void)
{
    int randIndex = rand() % 3;

    switch (randIndex)
    {
    case 0:
        return new A;
    case 1:
        return new B;
    case 2:
        return new C;
    }

    return NULL;
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p)
{

   try
   {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
   }
   catch(...) {}

   try
   {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
   }
   catch(...) {}

   try
   {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
   }
   catch(...) {}
   
   
}

int main(void)
{
    srand(time(NULL));

    for (int i = 0; i < 11; i++)
    {
        Base *t = generate();
        identify(t);
        identify(*t);
        delete t;
    }
    
    return 0;
}