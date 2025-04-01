#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (*str < 32 || *str > 126)
			return (0);
		str++;
	}
	return (1);
}

int	main()
{
	int	a;
	char	str[] = " !~\xa0";
	
	a = ft_str_is_printable(str);
	if (a)
		printf("PRINTAble\n");
	else
		printf("NOT PRINTABLE\n");
	return (0);
}
