#include <unistd.h>

int	ft_strlen(char	*str)
{
	int	index;
	
	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}
int	ft_strcmp(char *str, char letter)
{
	while (*str)
	{
		if (*str == letter)
			return (0);
		str++;
	}
	return (1);
}

int	print(char *str, char letter)
{
	while (*str)
	{
		if (*str == letter)
		{
			write(1, &letter, 1);
			return (1);
		}
		str++;
	}
	return (0);
}

void	print_string(char *s1, char *s2)
{
	char	arr[ft_strlen(s1) + 1];
	int	index;

	arr[0] = '\0';
	index = 0;
	while (*s1 != '\0')
	{
		if (ft_strcmp(arr, *s1))
		{
			arr[index] = *s1;
			index++;
		}
		s1++;
	}
	arr[index] = '\0';
	index = 0;
	while (arr[index] != '\0')
	{
		print(s2, arr[index]);
		index++;
	}
	write(1, "\n", 1);
}


int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	print_string(argv[1], argv[2]);
	return (0);
}
