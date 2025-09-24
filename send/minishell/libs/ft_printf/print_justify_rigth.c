/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_justify_rigth.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:18:12 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 10:40:26 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_justify_rigth(t_format flag, int *length)
{
	if (!flag.justify && !flag.padding)
	{
		while (*length < flag.width)
		{
			ft_putchar(' ', 1);
			(*length)++;
		}
	}
}
