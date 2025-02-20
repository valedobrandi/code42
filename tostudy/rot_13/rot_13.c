#include <unistd.h>
#include <stdio.h>
void	print_lowercase(char str)
{
	int	temp;
	char	letter;

	temp = 0;
	if (str > 'm')
	{
		temp = 12 - ('z' - str);
		letter = 'a' + temp;
		write(1, &letter, 1);
	}
	else
	{
		letter = str + 13;
		write(1, &letter, 1);
	}
}
void	print_uppercase(char str)
{
	int	temp;
	char	letter;

	temp = 0;
	if (str > 'M')
	{
		temp = 12 - ('Z' - str);
		printf("%d", temp);
		letter = 'A' + temp;
		write(1, &letter, 1);
	}
	else
	{
		letter = str + 13;
		write(1, &letter, 1);
	}
}

int	main(int argc, char **argv)
{
	int	index;

	index = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][index] != '\0')
	{
		if (argv[1][index] >= 'a' && argv[1][index] <= 'z')
			print_lowercase(argv[1][index]);
		else if (argv[1][index] >= 'A' && argv[1][index] <= 'Z')
			print_uppercase(argv[1][index]);
		else
			write(1, &argv[1][index], 1);
		index++;
	}
	write(1, "\n", 1);	
	return (0);
}