#include <stdio.h>
#include <stdlib.h>

char    *ft_strdup(char *src)
{
    int    n;
    char    *ptr;

    n = 0;
    while (src[n])
        n += 1;
    ptr = (char*)malloc(n * sizeof(int));
    if (!ptr)
        return (NULL);    
    ptr = src;
    return (ptr); 
}

int    main(void)
{
    char source[] = "GeeksForGeeks";

    char    *target = ft_strdup(source);
    for (int i = 0;i < 11; i += 1)
        printf("%c", target[i]);
    printf("\n");
}
