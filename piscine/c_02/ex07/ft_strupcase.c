#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{

	(void)argc;
	char *a = ft_strupcase(argv[1]);
       	printf("%s\n", a);
	
	return (0);
}
