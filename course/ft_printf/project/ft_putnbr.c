/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 08:37:02 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/04 08:51:29 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

size_t	print(long n, int fd)
{
	char	num;
    size_t  length;

    length = 0;
	if (n >= 10)
		length += print(n / 10, fd);
	num = (n % 10) + '0';
	write(fd, &num, 1);
    return (length + 1);
}

size_t	ft_putnbr(int n, int fd)
{
	long	long_n;
    size_t  len;

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
