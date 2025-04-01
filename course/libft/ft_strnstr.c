#include <stddef.h>

static int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    while (*s1 && *s2 && n)
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
        n--;
    }
    return (*s1 - *s2);
}

char    *ft_strstr (const char *str_1, const char *str_2)
{
    unsigned int    index;

    index = 0;
    while (str_2[index])
        index++;
    if (index == 0)
        return ((char *)str_1);
    while (*str_1)
    {
        if (*str_1 == *str_2 && ft_strncmp(str_1, str_2, index) == 0)
            return ((char *)str_1);
        str_1++;
    }

    return ((void *)0);
}