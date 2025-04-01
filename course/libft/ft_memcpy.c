
#include <stddef.h>

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *d;
    unsigned char *s;

    d = (unsigned char *)dest;
    s = (unsigned char *)src;
    while (n--)
        *d++ = *s++;
        
    return (dest);
}
 