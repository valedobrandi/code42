/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:01:12 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 10:40:53 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	print_i_d(t_format flag, int num)
{
	int	length;
	int	number_length;

	number_length = ft_nbrlen(num);
	length = number_length;
	print_justify_rigth(flag, &length);
	if (num < 0)
	{
		ft_putchar('-', 1);
		number_length--;
	}
	print_space(flag, num, &length);
	print_sign(flag, num, &length);
	if ((flag.precision - number_length) > 0)
		print_precision(flag, &length, flag.precision - number_length);
	print_padding(flag, &length);
	ft_putnbr(num, 1);
	print_justify_left(flag, &length);
	return (length);
}
