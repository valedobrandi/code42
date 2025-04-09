#include "ft_printf.h"
#include "libft/libft.h"

int print_c(t_format flags, int print)
{
    int  length;

    length = 1;
    print_justify_rigth(flags, &length);
    print_padding(flags, &length);
    ft_putchar(print, 1);
    print_justify_left(flags, &length);

    return (length);
};
