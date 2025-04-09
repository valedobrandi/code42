#include "ft_printf.h"
#include "libft/libft.h"

size_t	ft_putnbrlen_base(unsigned long n, char *base)
{
	size_t	base_length;
	size_t	count;	

    count = 0;
	base_length = ft_strlen(base);
    if (base_length < 2)
            return (0);
	if (n >= base_length)
        count += ft_putnbrlen_base(n / base_length, base);
    count++;
    return (count);
}

int print_u_x_upperx(t_format flags, unsigned long n,  char *base)
{
    int  length;
    int number_length;

    number_length = ft_putnbrlen_base(n, base);
    length = number_length;
    print_justify_rigth(flags, &length);
    if (flags.sharp && n != 0)
    {
        if (flags.type =='x')
            length += ft_putstr("0x", 1);
        if (flags.type =='X')
            length += ft_putstr("0X", 1);
    }
    if ((flags.precision - number_length) > 0)
        print_precision(flags, &length, flags.precision - number_length);
    print_padding(flags, &length);
    ft_putnbr_base(n, base);
    print_justify_left(flags, &length);
    return (length);
};