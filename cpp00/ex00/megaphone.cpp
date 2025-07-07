#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int j = 1; j < argc; j++)
    {
        for (int i = 0; argv[j][i]; i++)
        {
            char c = argv[j][i];
            if (c >= 'a' && c <= 'z') 
                c = c - 32;
            std::cout << c;
        }
    }
    std::cout << std::endl;  
    return (0);
}
