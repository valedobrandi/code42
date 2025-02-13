#include <stdlib.h>
#include <stdio.h>
int    ft_ultimate_range(int **range, int min, int max)
{
	int    index;
	int    length;
	
	*range = NULL;
	if (min >= max)
		return (0);
	
	length = max - min;
	*range = (int *)malloc(length * sizeof(int));
	if (!*range)
		return (-1);
	index = 0;
	while (min < max)
	{
		(*range)[index] = min;
		index += 1;
		min = min + 1;
	}
	return (length);
}
