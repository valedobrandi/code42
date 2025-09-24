/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:18:44 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 10:40:02 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_precision(t_format flag, int *length, int number_length)
{
	while (flag.has_precision && number_length > 0)
	{
		ft_putchar('0', 1);
		(*length)++;
		number_length--;
	}
}
