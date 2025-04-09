#include "ft_printf.h"
#include "libft/libft.h"

void parse_type(t_format *flags, const char *format, int *index)
{
    if (format[*index] != '\0' && ft_strrchr("cspdiuxX%", format[*index]))
        flags->type = format[*index];

}