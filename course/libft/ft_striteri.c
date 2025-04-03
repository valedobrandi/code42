#include <stddef.h>

void    ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    int index;

    if (!s || !f)
        return;
    index = 0;
    while (s[index] != '\0')
    {
        f(index, &s[index]);
        index++;
    }
}