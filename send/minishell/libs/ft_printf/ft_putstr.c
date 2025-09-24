/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 08:37:08 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 10:14:36 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int fd)
{
	int	index;

	index = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[index] != '\0')
	{
		write(fd, &s[index], 1);
		index++;
	}
	return (index);
}
