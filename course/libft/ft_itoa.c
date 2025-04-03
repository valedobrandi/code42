#include <stddef.h>
#include <stdlib.h>

static char	*ft_strdup(const char *s)
{
	char *ptr;
	size_t index;

	index = 0;
	while (s[index])
		index++;
	ptr = (char *)malloc((index + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		ptr[index] = s[index];
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}

void    recpy(int n, char *ptr, size_t *len)
{
    if (n == 0)
        return;
    recpy((n / 10), ptr, len);
    ptr[*len] = (n % 10) + '0';
    (*len)++;
}

char    *init(int n)
{
    int cpy;
    size_t   len;
    char    *ptr;

    cpy = n;
    len = 0;
    if (cpy < 0)
    {
        cpy *= -1;
        len++;
    }
    while (cpy > 0)
    {
        cpy = cpy / 10;
        len++;
    }
    ptr = (char *)malloc((len + 1) * sizeof(char));
    if (!ptr)
        return (NULL);
    return (ptr);
}

char    *ft_itoa(int n)
{
    size_t   len;
    char    *ptr;

    ptr = '\0';
    if (n == 0)
        return (ft_strdup("0"));
    ptr = init(n);
    if (!ptr)
        return (NULL);
    len = 0;
    if (n < 0)
    {
        n *= -1;
        *ptr = '-';
        len++;
    }
    recpy(n, ptr, &len);
    ptr[len] = '\0';
    return (ptr);    
}