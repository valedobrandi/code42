/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:52:54 by bde-albu          #+#    #+#             */
/*   Updated: 2025/02/19 13:40:16 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr(int nb)
{
	long	lnb;
	char	number;

	lnb = nb;
	if (lnb < 0)
	{
		write(1, "-", 1);
		lnb *= -1;
	}
	if (lnb >= 10)
		ft_putnbr(lnb / 10);
	number = lnb % 10 + '0';
	write(1, &number, 1);

}

int	main(int argn, char **argv)
{
	(void)argn;
	ft_putnbr(atoi(argv[1]));
}