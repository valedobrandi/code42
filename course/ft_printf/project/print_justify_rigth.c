#include "ft_printf.h"
#include "libft/libft.h"

void print_justify_rigth(t_format flags, int *length)
{
    if (!flags.justify && !flags.padding)
    {
        while (*length < flags.width)
        {
            ft_putchar(' ', 1);
            (*length)++;
        }
    }
};