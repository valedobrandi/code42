/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:09:40 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 10:19:09 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_sign(t_format flag, int num, int *length)
{
	if (flag.sign && num >= 0)
	{
		ft_putchar('+', 1);
		(*length)++;
	}
}
