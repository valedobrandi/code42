#include "ft_printf.h"
#include "libft/libft.h"

void print_precision(t_format flags, int *length, int number_length)
{
    while (flags.has_precision && number_length > 0)
    {
         ft_putchar('0', 1);
         (*length)++;
         number_length--;
    }
};