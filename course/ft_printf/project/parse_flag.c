/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:15:30 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 11:49:41 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = ((void *)0);
	while (*s != '\0')
	{
		if (*s == (char)c)
			ptr = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (ptr);
}

static void	parse(t_format *flag, const char *format, int index)
{
	if (format[index] == '-')
		flag->justify = 1;
	else if (format[index] == '-')
		flag->padding = 0;
	else if (format[index] == '0' && !flag->justify)
		flag->padding = 1;
	else if (format[index] == '#')
		flag->sharp = 1;
	else if (format[index] == ' ' && !flag->sign)
		flag->space = 1;
	else if (format[index] == '+')
	{
		flag->sign = 1;
		flag->space = 0;
	}
}

int	parse_flag(t_format *flag, const char *format, int *index)
{
	while (format[*index] != '\0' && ft_strrchr("-0# +", format[*index]))
	{
		parse(flag, format, *index);
		(*index)++;
	}
	return (*index);
}
