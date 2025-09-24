/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:14:50 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 10:14:56 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	init_format(void)
{
	t_format	f;

	f.justify = 0;
	f.padding = 0;
	f.precision = 0;
	f.has_precision = 0;
	f.sharp = 0;
	f.space = 0;
	f.sign = 0;
	f.width = 0;
	f.type = '\0';
	return (f);
}
