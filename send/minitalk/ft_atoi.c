/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:41:03 by bde-albu          #+#    #+#             */
/*   Updated: 2025/05/20 09:09:19 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *nptr)
{
	long	total;
	int		flag;

	flag = 1;
	total = 0;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			flag *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		total = total * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)(total * flag));
}
