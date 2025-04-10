/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_x_upperx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:02:53 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 11:54:52 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *s)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

static int	ft_putnbrlen_base(unsigned long n, char *base)
{
	unsigned long	base_length;
	int				count;

	count = 0;
	base_length = ft_strlen(base);
	if (base_length < 2)
		return (0);
	if (n >= base_length)
		count += ft_putnbrlen_base(n / base_length, base);
	count++;
	return (count);
}

int	print_u_x_upperx(t_format flag, unsigned long n, char *base)
{
	int	length;
	int	number_length;

	number_length = ft_putnbrlen_base(n, base);
	length = number_length;
	print_justify_rigth(flag, &length);
	if (flag.sharp && n != 0)
	{
		if (flag.type == 'x')
			length += ft_putstr("0x", 1);
		if (flag.type == 'X')
			length += ft_putstr("0X", 1);
	}
	if ((flag.precision - number_length) > 0)
		print_precision(flag, &length, flag.precision - number_length);
	print_padding(flag, &length);
	ft_putnbr_base(n, base);
	print_justify_left(flag, &length);
	return (length);
}
