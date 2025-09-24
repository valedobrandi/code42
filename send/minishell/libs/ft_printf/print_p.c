/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:02:04 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 10:40:20 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(t_format flag, void *ptr)
{
	int	length;

	length = 2;
	print_justify_rigth(flag, &length);
	print_padding(flag, &length);
	length = ft_putptr_hexa(ptr);
	print_justify_left(flag, &length);
	return (length);
}
