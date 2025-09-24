/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:00:58 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 10:40:59 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(t_format flag, int print)
{
	int	length;

	length = 1;
	print_justify_rigth(flag, &length);
	print_padding(flag, &length);
	ft_putchar(print, 1);
	print_justify_left(flag, &length);
	return (length);
}
