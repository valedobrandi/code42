#include <stdlib.h>
#include <stdio.h>
int    *ft_range(int min, int max)
{
	int	*table;
	int	length;
	int	index;
	
	table = NULL;
	if (min >= max)
		return (table);
	length = max - min;
	table = (int*)malloc(length * sizeof(int));
	if (!table)
		return NULL;
	index = 0;
	while (min < max)
	{
		table[index] = min;
		min = min + 1;
		index = index + 1;
	}
    return (table);
}

