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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	l;

	
	l = 0;
	i = ft_strlen(dest);

	while (src[l] != '\0')
	{
		dest[i] = src[l];
		l++;
		i++;
	}

	dest[i] = '\0';

	return dest;
}

int	main(void)
{
	char	*src = "Ramos";
	char	dest[15] = "Bernardo ";
	

	write(1, dest, 9);
	write(1, "| ", 2);
	write(1, src, 6);
	write(1, "\n", 1);
	ft_strcat(dest, src);
	write(1, dest, 15);
	write(1, "\n", 1);
}


