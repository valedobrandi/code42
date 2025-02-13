#include <unistd.h>
int	main(int argc, char **argv)
{
	int	index;
	int	length;

	index = argc - 1;
	while (index > 0)
	{
		length = 0;
		while (argv[index][length] != '\0')
		{
			write(1, &argv[index][length], 1);
			length = length + 1;
		}
		write(1, "\n", 1);
		index = index - 1;
	}
	
	return (0);
}

