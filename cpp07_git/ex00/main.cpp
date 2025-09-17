/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:42:15 by bde-albu          #+#    #+#             */
/*   Updated: 2025/09/16 14:05:43 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include "MyClass.hpp"

int main(void)
{
    {
        std::cout << std::endl << "PDF TEST" << std::endl;
        int a = 2;
        int b = 3;
        ::swap(a, b);
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
        std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
        std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    }
    {
        std::cout << std::endl << "VECTOR TEST" << std::endl;

        // Vector test
        std::vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        std::vector<int> v2;
        v2.push_back(4);
        v2.push_back(5);
        ::swap(v1, v2);
        std::cout << "v1 size = " << v1.size() << ", v2 size = " << v2.size() << std::endl;

        const std::vector<int> &vmin = ::min(v1, v2);
        const std::vector<int> &vmax = ::max(v1, v2);
        std::cout << "min vector size = " << vmin.size() << std::endl;
        std::cout << "max vector size = " << vmax.size() << std::endl;
    }
    {
        std::cout << std::endl << "PAIR TEST" << std::endl;
        std::pair<int, int> p1 = std::make_pair(10, 20);
        std::pair<int, int> p2 = std::make_pair(5, 30);

        ::swap(p1, p2);

        std::cout << "p1 = (" << p1.first << ", " << p1.second << "), ";
        std::cout << "p2 = (" << p2.first << ", " << p2.second << ")" << std::endl;

        std::pair<int, int> pmin = ::min(p1, p2);
        std::pair<int, int> pmax = ::max(p1, p2);

        std::cout << "min = (" << pmin.first << ", " << pmin.second << ")" << std::endl;
        std::cout << "max = (" << pmax.first << ", " << pmax.second << ")" << std::endl;
    }
    {
        std::cout << std::endl << "CLASS TEST" << std::endl;
        MyClass a(100);
        MyClass b(200);

        ::swap(a, b);

        std::cout << "a.value = " << a.getValue() << ", b.value = " << b.getValue() << std::endl;

        const MyClass &min_obj = ::min(a, b);
        const MyClass &max_obj = ::max(a, b);

        std::cout << "min.value = " << min_obj.getValue() << std::endl;
        std::cout << "max.value = " << max_obj.getValue() << std::endl;

        return 0;
    }
}