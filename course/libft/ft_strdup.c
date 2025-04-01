#include <stddef.h>
#include <stdlib.h>


char    *ft_strdup(const char *s)
{
    char *ptr;
    size_t index;
    
    index = 0;
    while (s[index])
        index++;
    ptr = (char *)malloc((index + 1) * sizeof(char));
    if (!ptr)
        return (NULL);
    index = 0;
    while (s[index] != '\0')
    {
        ptr[index] = s[index];
        index++;
    }
    ptr[index] = '\0';
    return (ptr);
}