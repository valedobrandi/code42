#include <unistd.h>
#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	isLower;

	if (!*str) return (1);
	while (*str)
	{
		isLower = (*str >= 'A' && *str <= 'Z');
		if (!isLower) return (0);
		str++;
	}
	return (1);
}

int	main(void)
{
	char	*arr[] = {"A", "ABC", "Ab", "#zB", ""};
	int	t;

	for (int i = 0; i < 5; i++)
	{
		t = ft_str_is_lowercase(arr[i]);
		if (t == 1) printf("%s - PASS | ", arr[i]);
		else printf("%s - FAIL | ", arr[i]);
	}
	printf("\n");
	return (0);
}
