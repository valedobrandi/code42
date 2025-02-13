#include <stdio.h>
#include <stdlib.h>

char    *ft_strdup(char *src)
{
    int    index;
    char    *ptr;

    index = 0;
    while (src[index] != '\0')
	    index += 1;
    ptr = (char*)malloc(index + 1 * sizeof(char));
    if (!ptr)
        return (NULL);    
    index = 0;
    while (src[index] != '\0')
    {
    	ptr[index] = src[index];
	index = index + 1;
    }
    ptr[index] = '\0';
    return (ptr); 
}

