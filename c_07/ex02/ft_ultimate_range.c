#include <stdlib.h>
#include <stdio.h>
int    ft_ultimate_range(int **range, int min, int max)
{
    int    i;
    int    size;

    *range = NULL;
    if (min > max)
        return (0);
    
    size = max - min;
    *range = (int *)malloc(size * sizeof(int));
    if (!*range)
        return (-1);

    i = 0;
    while (i < size)
    {
        (*range)[i] = min + i;  
        i += 1;
    }

    return (size);
}

int    main(void)
{
    int    *table;
    int    r;

    r = ft_ultimate_range(&table, 1, 20);
    printf("%d\n", r);
    for (int i = 0; i < r; i++)
        printf("%d", table[i]);
    printf("\n");
    free(table);
    return (0);
}