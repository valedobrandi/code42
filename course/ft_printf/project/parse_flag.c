#include "ft_printf.h"
#include "libft/libft.h"
// [flags][width][.precision][type]
int parse_flag(t_format *flags, const char *format, int *index)
{
  while (format[*index] != '\0' && ft_strrchr("-0# +", format[*index]))
  {
    if (format[*index] == '-')
    {
      flags->justify = 1;
      flags->padding = 0;
    }
    else if (format[*index] == '0')
    {
      if (!flags->justify)
        flags->padding = 1;
    }
    else if (format[*index] == '#')
      flags->sharp = 1;
    else if (format[*index] == ' ')
    {
      if (!flags->sign)
        flags->space = 1;
    }
    else if (format[*index] == '+')
    {
      flags->sign = 1;
      flags->space = 0;
    }
    (*index)++;
  }
  return (*index);
}

/* flags->justify
flags->padding
flags->alternate
flags->space
flags->sign */