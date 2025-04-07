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

#include "libft_printf.h"
#include "../libft/libft.h"

void	ft_putptr_hexa(void *ptr)
{
	unsigned long long addr = (unsigned long long)ptr;
	char *base = "0123456789abcdef";

	ft_putstr_fd("0x", 1);
	if (addr == 0)
		ft_putchar_fd('0', 1);
	else
		ft_putnbr_base(addr, base);
		

}