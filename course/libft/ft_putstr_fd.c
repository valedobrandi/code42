#include <unistd.h>

void    ft_putstr_fd(char *s, int fd)
{
    int index;

    index = 0;
    if (!s)
        return;
    while (s[index] != '\0')
    {
        write(fd, &s[index], 1);
        index++;
    }
}