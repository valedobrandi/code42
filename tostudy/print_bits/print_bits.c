#include <unistd.h>

void	print_bits(char	octet)
{
	int	bit;
	char	c;

	bit = 7;
	while (bit >= 0)
	{
		if ((octet >> bit) & 1)
			c = '1';
		else
			c = '0';
		write(1, &c, 1);
		bit--;
	}
}