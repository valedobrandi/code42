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

static void	print(long n, int fd)
{
	char	num;

	if (n == 0)
		return ;
	num = (n % 10) + '0';
	print(n / 10, fd);
	write(fd, &num, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	long_n;

	long_n = n;
	if (long_n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (long_n < 0)
	{
		write(fd, "-", 1);
		long_n *= -1;
	}
	print(long_n, fd);
}
