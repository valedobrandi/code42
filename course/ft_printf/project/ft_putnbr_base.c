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

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

size_t	ft_putnbr_base(unsigned long n, char *base)
{
	size_t	base_length;
	size_t	count;	

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