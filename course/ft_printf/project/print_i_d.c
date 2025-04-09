#include "ft_printf.h"
#include "libft/libft.h"

int print_i_d(t_format flags, int num)
{
    int  length;
    int number_length;

    number_length = ft_nbrlen(num);
    length = number_length;
    print_justify_rigth(flags, &length);
    if (num < 0)
    {
        ft_putchar('-', 1);
        number_length--;
    }
    if (flags.space && num >= 0)
    {
        ft_putchar(' ', 1);
        length++;
    }
    else if (flags.sign && num >= 0)
    {
        ft_putchar('+', 1);
        length++;
    }
    if ((flags.precision - number_length) > 0)
        print_precision(flags, &length, flags.precision - number_length);
    print_padding(flags, &length);
    ft_putnbr(num, 1);
    print_justify_left(flags, &length);
    return (length);
};