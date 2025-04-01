
#include <stddef.h>

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *d;
    const unsigned char *s;
    size_t  i;

    s = (const unsigned char *)src;
    d = (unsigned char *)dest;
    i = 0;
    if (d > s)
        while(n--)
            d[n] = s[n];
    else
        while (i < n)
        {
            d[i] = s[i];
            i++;
        }
    return (dest);
}       