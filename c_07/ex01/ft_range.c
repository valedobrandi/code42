#include <stdlib.h>
#include <stdio.h>
int    *ft_range(int min, int max)
{
    int    *table;
    int    i;

    max -= 1;
    if (min >= max)
        return (NULL);
    table = (int*)malloc(max * sizeof(int));
    if (!table)
        return NULL;
    i = 0;
    while (i < 19)
    {
        table[i] = min + i;
        i += 1;
    }

    return table;
}
/*
int    main(void)
{
    int *table;

    table = ft_range(1, 20);
    for (int i = 0; i < 19; i += 1)
        printf("%d", table[i]);
    printf("\n");
    return (0);
}
*/
