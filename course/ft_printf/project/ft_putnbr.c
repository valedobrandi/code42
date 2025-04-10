/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 08:37:02 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 10:14:02 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	print(long n, int fd)
{
	char	num;
	int		length;

	length = 0;
	if (n >= 10)
		length += print(n / 10, fd);
	num = (n % 10) + '0';
	write(fd, &num, 1);
	return (length + 1);
}

int	ft_putnbr(int n, int fd)
{
	long	long_n;
	int		len;

	long_n = n;
	len = 0;
	if (long_n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (long_n < 0)
		long_n *= -1;
	len += print(long_n, fd);
	return (len);
}
