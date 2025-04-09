#include "ft_printf.h"
#include "libft/libft.h"

int print_s(t_format flags, char *print)
{
    int  length;
    char    *buffer;
    int     is_malloc;

    is_malloc = 0;
    length = ft_strlen(print);
    if (flags.has_precision && flags.precision < length)
    {
        buffer = (char *)malloc((flags.precision + 1) * (sizeof(char)));
        if (!buffer)
            return (0);
        ft_strlcpy(buffer, print, flags.precision + 1);
        length = ft_strlen(buffer);
        is_malloc = 1;
    }
    else
        buffer = print;
    print_justify_rigth(flags, &length);
    print_padding(flags, &length);
    ft_putstr(buffer, 1);
    print_justify_left(flags, &length);
    if (is_malloc)
        free(buffer);
    return (length);
};