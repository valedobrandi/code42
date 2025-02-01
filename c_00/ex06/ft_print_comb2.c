#include <stdio.h>
#include <unistd.h>

int	ft_comb1()
{
	int     a = '0';
        int     b = '0';
        int     c = '0';
	int	d = '1';

        while (a <= '9')
        {
		while (b <= '8')
		{
			while (c <= '9')
			{	
                		while (d <= '9')
                		{
					
                        		write(1, &a, 1);
					write(1, &b, 1);
					write(1, " ", 1);
                        		write(1, &c, 1);
					write(1, &d, 2);
					if (!(a == '9' && b == '8' && c == '9' && d == '9'))
					{		
						write(1, ", ", 2);
					}
					d++;
                		}
				c++;
				d = '0';
       			}
			b++;
			c = '0';
			d = b + 1;
		}
		a++;
		b = '0';
	}
}


int	main()
{

	ft_comb1();
	return (0);
}
