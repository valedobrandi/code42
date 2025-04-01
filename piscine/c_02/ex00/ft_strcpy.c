#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
	       	index++;

	}
	dest[index] = '\0';
}

int	main(void)
{
	char	str[] = "Bernardo";
	char	dest[8];

	ft_strcpy(dest, str);
	write(1, dest, 8);
	return (0);
}
