#include <unistd.h>

void	ft_putnbr_hex(unsigned int n)
{
	char	*hex = "0123456789abcdef";

	if (n >= 16)
		ft_putnbr_hex(n / 16);
	write(1, &hex[n % 16], 1);
}

int	main(int argc, char **argv)
{
	unsigned int	num;
	int				i;

	if (argc == 2)
	{
		num = 0;
		i = 0;
		while (argv[1][i])
		{
			num = num * 10 + (argv[1][i] - '0');
			i++;
		}
		ft_putnbr_hex(num);
	}
	write(1, "\n", 1);
	return (0);
}
