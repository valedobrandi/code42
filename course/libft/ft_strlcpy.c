#include <stddef.h>
#include <stdio.h>


size_t  ft_strlcpy(char *dst, const char *restrict src, size_t dsize)
{
    size_t i;
    size_t j;

    i = 0;
    while (src[i] != '\0')
        i++;
    if (dsize == 0)
        return (i);
    j = 0;
    while (j < (dsize - 1) && src[j] != '\0')
    {
        dst[j] = src[j];
        j++;  
    }
    dst[j] = '\0';

    return (i);
}