#include <stdio.h>

void	ft_print_comb2(void)
{
	int	a = 0;
	int 	b = 1;

	int	c = 0;
	int	d = 0;
	while(c <= 9)
	{
		while (b <= 9)
		{
			printf("%d%d%s%d%d%s", c, d, " ", a, b, ",");
			b++;
		}
		a++;
		if (a == 9)
		{
			d++;
			a = 0;
		}
		else if (d == 9)
		{
			c++;
			d = 0;
		}
		b = 0;

	}
	
}

int	main()
{
	ft_print_comb2();
	return (0);
}
