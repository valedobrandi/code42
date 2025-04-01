#include <stdio.h>
#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	while ((s1[i] && s2[i]) && (i < n - 1))
        { 
		if (s1[i] != s2[i]) return (s1[i] - s2[i]);
		i++;
        }
        return (s1[i] - s2[i]);
}

int	main(void)
{
	char	*arr_a[] = {"ABC", "ABC"};
	char    *arr_b[] = {"AB", "AB"};
	int	arr_c[] = {3, 2};
	int	t;
		
	for (int i = 0; i < 2; i++)
	{
		t = ft_strncmp(arr_a[i], arr_b[i], arr_c[i]);
		if (t > 0) printf("%s is greater than %s - %d ", arr_a[i], arr_b[i], arr_c[i]);	
		else printf("%s is equal to %s - %d", arr_a[i], arr_b[i], arr_c[i]);
		
		printf("\n");
	}
	return (0);
}


