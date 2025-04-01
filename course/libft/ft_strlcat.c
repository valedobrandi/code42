#include <stddef.h>

size_t ft_strlcat(char *dst, const char *restrict src, size_t dsize)
{
    size_t size_src;
    size_t size_dst;
    size_t index;

    size_src = 0;
    while (src[size_src] != '\0')
        size_src++;
    size_dst = 0;
    while (dst[size_dst] != '\0')
        size_dst++;
    if (dsize <= size_dst)
        return (dsize + size_src);
    index = 0;
    while (index < (dsize - 1) && src[index] != '\0')
    {
        dst[size_dst + index] = src[index];
        index++;
    }
    dst[index + size_dst] = '\0';
    return (size_dst + size_src);
}