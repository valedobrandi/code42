#include "ft_printf.h"
#include "libft/libft.h"

void print_padding(t_format flags, int *length)
{
    if (flags.padding)
    {
        while (*length < flags.width)
        {
            ft_putchar('0', 1);
            (*length)++;
        }
    }
};