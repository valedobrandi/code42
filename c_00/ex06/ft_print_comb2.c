#include <stdio.h>
#include <unistd.h>

int	ft_comb1()
{
	int     a;
        int     b;
        int     c;
	int	d;
	
	a = '0';
        while (a <= '9')
        {
		b = '0';
		while (b <= '9')
		{
			c = a;
			d = b + 1;
			while (c <= '9')
			{	
                		while (d <= '9')
                		{
					
                        		write(1, &a, 1);
					write(1, &b, 1);
					write(1, " ", 1);
                        		write(1, &c, 1);
					write(1, &d, 1);
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
		}
		a++;
	}
}


int	main()
{

	ft_comb1();
	return (0);
}
