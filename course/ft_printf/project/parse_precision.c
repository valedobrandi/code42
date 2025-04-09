#include "ft_printf.h"
#include "libft/libft.h"

int parse_precision(t_format *flags, const char *format, int *index)
{
  if (format[*index] != '\0' && format[*index] == '.')
  {
    (*index)++;
      flags->has_precision = 1;
    if (ft_isdigit(format[*index]))
    {
      while (ft_isdigit(format[*index]))
      {
        flags->precision = flags->precision * 10 + (format[*index] - '0');
        (*index)++;
      }
    }
  }
  return (*index);
}