#include <stdio.h>
#include <unistd.h>

int ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2) 
			return (*s1 - *s2);
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

int	main(void)
{
	char	*arr_a[] = {"ABC", "ABC", "ABC", "ABA", "ABJ", "\201"};
	char    *arr_b[] = {"", "ABC", "AB", "ABZ", "ABC", "A"};
	int	t;
	
	for (int i = 0; i < 6; i++)
	{
		t = ft_strcmp(arr_a[i], arr_b[i]);
		if (t > 0) printf("%s is greater than %s ", arr_a[i], arr_b[i]);	
		else if (t < 0) printf("%s is lesser than %s ", arr_a[i], arr_b[i]);
		else printf("%s is equal than %s ", arr_a[i], arr_b[i]);
		
		printf("\n");
	}
	return (0);
}
