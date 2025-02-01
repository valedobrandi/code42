#include <stdio.h>
#include <unistd.h>

void	ft_print_comb(void)
{	
	int	a = '0';
	int	b = '1';
	int	c = '2';

	while (a <= '7')
	{
		while (c <= '9')
		{
			write(1, &a, 1);
			write(1, &b, 1);
			write(1, &c, 1);
			
			if (!(a == '7' && b == '8' && c == '9'))
			{
				write(1, ", ", 2);
			}
			c++;
		}
		

		if (b == '8')
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
