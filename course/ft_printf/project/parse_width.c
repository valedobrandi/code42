#include "ft_printf.h"
#include "libft/libft.h"

int parse_width(t_format *flags, const char *format, int *index)
{
    while (ft_isdigit(format[*index]))
    {
        flags->width = flags->width * 10 + (format[*index] - '0');
        (*index)++;
    }
    return (*index);
}