/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:17:35 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 11:49:09 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

int	parse_precision(t_format *flag, const char *format, int *index)
{
	if (format[*index] != '\0' && format[*index] == '.')
	{
		(*index)++;
		flag->has_precision = 1;
		if (ft_isdigit(format[*index]))
		{
			while (ft_isdigit(format[*index]))
			{
				flag->precision = flag->precision * 10 + (format[*index] - '0');
				(*index)++;
			}
		}
	}
	return (*index);
}
