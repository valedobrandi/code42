#include <unistd.h>
void	ft_putchar(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		write(1, &str[index], 1);
		index = index + 1;
	}
	write(1, "\n", 1);
}

int     main(int argc, char **argv)
{
	int	size;
	int	sort;

	(void)argc;
	sort = 32;
        while (sort < 127)
        {
		size = 1;
		while (argv[size])
		{ 
			if (argv[size][0] == sort)
				ft_putchar(argv[size]);
                	size = size + 1;
        	}
		sort = sort + 1;
	}
        return (0);
}

