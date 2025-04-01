#include <stddef.h>

char    *ft_strrchr(const char *s, int c)
{
    char    *ptr;

    ptr = ((void *)0);
    while (*s != '\0')
    {
        if (*s == (char)c)
            ptr = (char *)s;
        s++;
    }
    if ((char)c == '\0')
        return ((char *)s);
    return (ptr);
}