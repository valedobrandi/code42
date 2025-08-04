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

#include "Serializer.hpp"

int main(void)
{

    {
        struct Data t;
        struct Data *n;

        t.word = "Hello World";
        t.number = 100;

        uintptr_t x = Serializer::serialize(&t);
        n = Serializer::deserialize(x);

        std::cout << t.word << " " << n->word << std::endl;
        std::cout << t.number << " " << n->number << std::endl;

        std::cout << &t << " " << n << std::endl;

        if (&t == n)
            std::cout << "OK" << std::endl;
    }

    {
        Data arr[3];
        arr[0].word = "Hello";
        arr[0].number = 1;
        arr[1].word = "World";
        arr[1].number = 2;
        arr[2].word = "!";
        arr[2].number = 3;

        uintptr_t raw = Serializer::serialize(&arr[0]);
        Data *recovered = Serializer::deserialize(raw);

        std::cout << recovered[1].word << " " << recovered[1].number << std::endl;
    }


    return 0;
}