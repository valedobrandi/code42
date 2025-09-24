/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:10:45 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 11:54:40 by bde-albu         ###   ########.fr       */
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

int	ft_putnbr_base(unsigned long n, char *base)
{
	unsigned long	base_length;
	int				count;

	count = 0;
	base_length = ft_strlen(base);
	if (base_length < 2)
		return (0);
	if (n >= base_length)
		count += ft_putnbr_base(n / base_length, base);
	ft_putchar(base[n % base_length], 1);
	count++;
	return (count);
}
