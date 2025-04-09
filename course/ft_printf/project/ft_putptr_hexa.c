/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:06:25 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/07 16:58:25 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putptr_hexa(void *ptr)
{
	unsigned long long addr = (unsigned long long)ptr;
	char *base = "0123456789abcdef";
    size_t  count;

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