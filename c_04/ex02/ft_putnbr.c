#include <unistd.h>
void strev(char *str)
{
	int	i;
	int	index;
	char	t;
	index = 0;
	while(str[index] != '\0')
	{
		index++;
	}
	i = 0;
	while (i < (index - 1))
	{
		t = str[i];
		str[i] = str[index -1];
		str[index - 1] = t;
		index--;
		i++;	
	}

}


void	ft_putnbr(int nb)
{
	int	cpnb;
	int	index;
	char	str[15];

	str[0] = '\0';
	
	cpnb = nb;
	if (nb < 0)
	{
		nb = -nb;
	}
	index = 0;
	while (nb > 0)
	{
		str[index] = (nb % 10) + '0';
		nb = nb / 10;
		index++;
	}
	if (cpnb < 0)
	{
		str[index] = '-';
		index++;
	}
	str[index] = '\0';
	strev(str);
	write(1, str, index);
}

int	main(void)
{
	int	arr[] = {42, -567, 123, -1};

	for (int i = 0; i < 4; i++)
	{
		ft_putnbr(arr[i]);
		write(1, "\n", 1);
	}
	return (0);
}
