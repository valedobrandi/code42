#include <unistd.h>
#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	if (!*str)	return (1);
	while (*str)
	{
		if (!((*str >= 'a' &&  *str <= 'z') || (*str >= 'A' && *str <= 'Z')))
		{
			return (0);
		}
		
		str++;
	}
	return (1);
}
int	main(void)
{
	char	pass[] = "bernardo";
	char	fail[] = "Ber1ardo";
	char	empty[] = "";
	int	test;

	test = ft_str_is_alpha(pass);
	if (test == 1) 
	{
		printf("bernardo - ");
		printf("%s\n", "PASS");
	}
	test = ft_str_is_alpha(fail);
        if (test == 0)
	{
		printf("ber1ardo - ");
		printf("%s\n", "FAIL");
	}
	test = ft_str_is_alpha(empty);
	if (test == 1)
        {
		printf(" - ");
                printf("%s\n", "PASS");
        }

}
