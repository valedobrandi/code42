#include <stdio.h>

void	ft_print_comb(void)
{	
	int	a = 0;
	int	b = 1;
	int	c = 2;

	while (a <= 7)
	{
		while (c <= 9)
		{
			printf("%d%d%d", a, b, c);
			
			if (a + b + c < 24 )
			{
				printf("%s", ",");
			}
			c++;
		}
		

		if (b == 8)
		{
			a++;
			b = a + 1;
			c = b + 1;
		}
		else
		{
			b++;
			c = b + 1;
		}
	}
}

int	main()
{
	ft_print_comb();
	return (0);
}
