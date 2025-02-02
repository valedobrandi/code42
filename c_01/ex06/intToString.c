#include <unistd.h>
#include <stdio.h>

int	intToString(int N, char *str)
{
	int	i;
	int	copy;

	i = 0;
	copy = N;

	if (N < 0)
	{
		N = -N;
	}

	while (N > 0)
	{
		str[i] = N % 10 + '0';
		N = N / 10;
		i++;
	}

	if (copy < 0)
	{	
		str[i] = '-';			
	}

	str[i] = '\0';
	
	int	l = 0;
	int	index = i - 1;
	int	length = index;
	while (l <= length)
	{
		char temp = str[l];
		str[l] = str[index];
		str[index] = temp;
		index--;
		l++;

	}

	return i;
}
