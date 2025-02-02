#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;

	while (str[count] != '\0')
	{
		count++;
	}

	return count;
}

int	main(void)
{
	char*	str = "123456789";
	int	length;
	
	length = ft_strlen(str);
	printf("%d%s", length, " \n");
	return (0);
}
