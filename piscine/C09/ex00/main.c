#include "libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	index;

	(void)argc;
	index = 0;	
	while (argv[1][index] != '\0')
	{
		ft_putchar(argv[1][index]);
		index = index + 1;
	}	
	printf("\nString length - %d", ft_strlen(argv[1]));
}
