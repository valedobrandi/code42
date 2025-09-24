/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_justify_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:18:03 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 10:40:28 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_justify_left(t_format flag, int *length)
{
	while (*length < flag.width && !flag.padding)
	{
		ft_putchar(' ', 1);
		(*length)++;
	}
}
