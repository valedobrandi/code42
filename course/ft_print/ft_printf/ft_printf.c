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

#include "libft_printf.h"
#include "../libft/libft.h"

int	ft_printf(const char *format, ...)
{
	va_list args;
	int	index;
	int	count;

	va_start(args, format);
	index = 0;
	count = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			if (format[index] == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (format[index] == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			else if (format[index] == 'p')
				ft_putptr_hexa(va_arg(args, void *));
			else if (format[index] == 'i' || format[index] == 'd')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (format[index] == 'u')
				ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
			else if (format[index] == 'x')
				ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
			else if (format[index] == 'X')
				ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
			else if (format[index] == '%')
				ft_putchar_fd(va_arg(args, int), 1);
			else
				ft_putchar_fd(format[index - 1], 1);
			index++;
		}
		ft_putchar_fd(format[index], 1);
		index++;
		count++;
	}
	va_end(args);

	return (count);
}