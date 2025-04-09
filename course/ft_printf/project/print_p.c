#include "ft_printf.h"
#include "libft/libft.h"

int print_p(t_format flags, void *ptr)
{
    int  length;

    length = 2;
    print_justify_rigth(flags, &length);
    print_padding(flags, &length);
    length = ft_putptr_hexa(ptr);
    print_justify_left(flags, &length);

    return (length);
};