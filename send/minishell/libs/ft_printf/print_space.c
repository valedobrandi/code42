/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:05:00 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 10:19:14 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_space(t_format flag, int num, int *length)
{
	if (flag.space && num >= 0)
	{
		ft_putchar(' ', 1);
		(*length)++;
	}
}
