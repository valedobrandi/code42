#include "iter.hpp"
#include <iostream>

void sum(int& t)
{
    ++t;
}

void print(const int& t)
{
    std::cout << t << " ";
}

void capitalize(std::string& t)
{
    long unsigned int n = t.size();
    for(long unsigned int  i = 0; i < n; i++)
        t[i] = std::toupper(t[i]);
}

int main(void)
{
    {
        int t[] = {0, 1, 2, 3, 4, 5};

        ::iter(t, 6, sum);

        for (int i = 0; i < 6; i++)
            std::cout << t[i] << " ";
    }
	std::cout << std::endl;
    {
        const int arr[] = {10, 20, 30};

        ::iter(arr, 3, print);
    }
	std::cout << std::endl;
    {
        std::string t[] = {"hello", "world", "test"};
        ::iter(t, 3, capitalize);
        for (int i = 0; i < 3; i++)
            std::cout << t[i] << " ";
    }

    return 0;
}