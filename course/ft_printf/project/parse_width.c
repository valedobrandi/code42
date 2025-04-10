/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:17:48 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 11:36:38 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

int	parse_width(t_format *flag, const char *format, int *index)
{
	while (ft_isdigit(format[*index]))
	{
		flag->width = flag->width * 10 + (format[*index] - '0');
		(*index)++;
	}
	return (*index);
}
