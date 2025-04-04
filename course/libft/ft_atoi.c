/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:41:03 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/04 08:55:30 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
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
