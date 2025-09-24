/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:31:53 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 11:43:41 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_print(int *count, t_format flag, va_list args)
{
	if (flag.type == 'c')
		*count += print_c(flag, va_arg(args, int));
	else if (flag.type == 's')
		*count += print_s(flag, va_arg(args, char *));
	else if (flag.type == 'p')
		*count += print_p(flag, va_arg(args, void *));
	else if (flag.type == 'i' || flag.type == 'd')
		*count += print_i_d(flag, va_arg(args, int));
	else if (flag.type == 'u')
		*count += print_u_x_upperx(flag, va_arg(args, unsigned int),
				"0123456789");
	else if (flag.type == 'x')
		*count += print_u_x_upperx(flag, va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (flag.type == 'X')
		*count += print_u_x_upperx(flag, va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (flag.type == '%')
		*count += ft_putchar('%', 1);
}
