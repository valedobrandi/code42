/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:10:45 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/07 17:10:48 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "../libft/libft.h"

void	ft_putnbr_base(int n, char *base)
{
	size_t	size;
	size_t	nsize;	

	size = sizeof(base);
	nsize = (int)n;
	if (nsize >= size)
		ft_putnbr_base(nsize / size, base);
	ft_putchar_fd(base[nsize % 16], 1);
}