#include <stdio.h>

void	ft_print_comb(void)
{
	int	a = 0;
	int	b = 1;
	int	c = 2;
	int	base = 7;
	int	count = 7;
	int 	timer = 0;
	while (a <= 7)
	{
		while (timer <= count)
		{
			printf("%d%d%d", a, b, c);
			c++;
			timer++;
			if (a + b + c < 24 )
			{
				printf("%s", ",");
			}
		}

		if (c + b == 17)
		{
			a++;
			b = a + 1;
			c = b + 1;
			timer = 0;
			base--;
		       	count = base;	
		}
		else
		{
			timer = 0;
			count--;
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
