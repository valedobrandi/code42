#include <unistd.h>
#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	e;
	
	if (!*str) return (1);
	while (*str)
	{
		e = (*str >= '0' && *str <= '9');
		if (!e) return (0);
		str++;
	}
	
	return (1);

}

int	main(void)
{
	char	*arr[] = {"0", "1AB", "", "123", "124a"};
	int	t;

	for (int i = 0; i < 5; i++)
	{
		t = ft_str_is_numeric(arr[i]);
		if (t == 1) printf("%s - PASS | ", arr[i]);
		else printf("%s - FAIL | ", arr[i]);	
	}
	printf("\n");
	return (0);	
}
