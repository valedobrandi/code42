#include <unistd.h>
#include <stdio.h>

void	ft_ft(int *nbr)
{	
	*nbr = *nbr + 10;
}

int	main(void)
{
	int	b;
	int	*ptr;
	b = 10;
	ptr = &b;
	
	printf("%d\n", *ptr);
	ft_ft(ptr);
	printf("%d\n", *ptr);
	return (0);
}
