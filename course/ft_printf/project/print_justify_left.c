#include "ft_printf.h"
#include "libft/libft.h"

void print_justify_left(t_format flags, int *length)
{
    while (*length < flags.width && !flags.padding)
    {
        ft_putchar(' ', 1);
        (*length)++;
    }
};