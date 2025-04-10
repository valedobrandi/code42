/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:44:46 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 09:45:42 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_printf(t_format *flag, const char *format, int *index)
{
	parse_flag(flag, format, index);
	parse_width(flag, format, index);
	parse_precision(flag, format, index);
	parse_type(flag, format, index);
}
