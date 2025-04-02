/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:41:03 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/02 10:41:06 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	unsigned int total;
	int flag;

	flag = 1;
	while (*nptr == ' ')
		nptr++;
	if (*nptr == '-')
		flag *= -1;
	nptr++;
	total = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		total += *nptr - '0';
		nptr++;
	}
	return (total * flag);
}