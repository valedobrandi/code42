#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    int index;
    char    *ptr;

    if (!s || !f)
        return (NULL);
    index = ft_strlen((char *)s);
    ptr = (char *)malloc((index + 1) * sizeof(char));
    if (!ptr)
        return (NULL);
    index = 0;
    while (s[index] != '\0')
    {
        ptr[index] = f(index, s[index]);
        index++;
    }
    ptr[index] = '\0';
    return (ptr);
}