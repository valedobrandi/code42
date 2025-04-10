/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:30:54 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 11:46:15 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			index;
	int			count;
	t_format	flag;

	index = 0;
	count = 0;
	va_start(args, format);
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			flag = init_format();
			index++;
			parse_printf(&flag, format, &index);
			manage_print(&count, flag, args);
		}
		else
		{
			ft_putchar(format[index], 1);
			count++;
		}
		index++;
	}
	return (count);
}
