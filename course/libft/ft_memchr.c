#include <stddef.h>

void    *ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char *ss;

    ss = (const unsigned char *)s;
    while (n > 0)
    {
        if ((unsigned char)c == *ss)
            return ((void *)ss);
        ss++;
        n--;
    }
    return (((void *)0));
}