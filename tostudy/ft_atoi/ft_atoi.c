int	ft_atoi(const char *str)
{
	long	result;
	int	flag;
	
	result = 0;
	flag = 1;
	while(*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	
	return ((int)(result * flag));
}
#include <stdio.h>
int	main(void)
{
	printf("%d", ft_atoi("     4525655"));
	return (0);
}
