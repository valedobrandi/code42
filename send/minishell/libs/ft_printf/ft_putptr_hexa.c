/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:06:25 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 10:14:26 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_hexa(void *ptr)
{
	unsigned long long	addr;
	char				*base;
	int					count;

	addr = (unsigned long long)ptr;
	base = "0123456789abcdef";
	count = 0;
	if (addr == 0)
	{
		count += ft_putstr("(nil)", 1);
		return (count);
	}
	count += ft_putstr("0x", 1);
	count += ft_putnbr_base(addr, base);
	return (count);
}
