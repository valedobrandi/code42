#include <unistd.h>

int	ft_search(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == 'a')
			return (1);
		index++;
	}
	return (0);
}

int	main(int argn, char **argv)
{

	if (argn != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (ft_search(argv[1]))
	{
		write(1, "a\n", 2);
	}
	else
	{
		write(1, "\n", 1);
	}
	return (0);
}