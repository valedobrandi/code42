#include "ft_printf.h"
#include "libft/libft.h"

t_format    init_format(void)
{
    t_format f;

    f.justify = 0;
    f.padding = 0;
    f.precision = 0;
    f.has_precision = 0;
    f.sharp = 0;
    f.space = 0;
    f.sign = 0;
    f.width = 0;
    f.type = '\0';
    return(f);
}