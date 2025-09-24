/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:18:33 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 10:40:07 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_padding(t_format flag, int *length)
{
	if (flag.padding)
	{
		while (*length < flag.width)
		{
			ft_putchar('0', 1);
			(*length)++;
		}
	}
}
