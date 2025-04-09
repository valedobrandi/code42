/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:30:54 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/07 17:00:19 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf(const char *format, ...)
{
	va_list args;
	int	index;
	size_t	count;
    t_format flags;

	va_start(args, format);
	index = 0;
	count = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
            flags = init_format();
			index++;
            parse_flag(&flags, format, &index );
            parse_width(&flags, format, &index);
            parse_precision(&flags, format, &index);
            parse_type(&flags, format, &index);
            if (flags.type == 'c')
                count += print_c(flags, va_arg(args, int));
            else if (flags.type == 's')
                count += print_s(flags, va_arg(args, char *));
            else if (flags.type == 'p')
                count += print_p(flags, va_arg(args, void *));
            else if (flags.type == 'i' || flags.type == 'd' )
                count += print_i_d(flags, va_arg(args, int));
            else if (flags.type == 'u')
                count += print_u_x_upperx(flags, va_arg(args, unsigned int), "0123456789");
            else if (flags.type == 'x')
                count += print_u_x_upperx(flags, va_arg(args, unsigned int), "0123456789abcdef");
            else if (flags.type == 'X')
                count += print_u_x_upperx(flags, va_arg(args, unsigned int), "0123456789ABCDEF");
            else if (flags.type == '%')
                count += ft_putchar('%', 1);
		}
        else
        {
		    ft_putchar(format[index], 1);
            count++;
        }
		index++;
	}
	va_end(args);
	return (count);
}