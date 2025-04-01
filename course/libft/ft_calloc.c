#include <stddef.h>
#include <stdlib.h>

static void    ft_bzero(void *s, size_t n)
{
    unsigned char *ptr;

    ptr = (unsigned char *)s;
    while (n--)
        *ptr++ = 0;
}

void    *ft_calloc(size_t nmemb, size_t size)
{
    size_t total;
    void    *ptr;

    total = nmemb * size;
    ptr = malloc(total);
    if (!ptr)
        return (NULL);
    ft_bzero(ptr, total);
    return (ptr);
}