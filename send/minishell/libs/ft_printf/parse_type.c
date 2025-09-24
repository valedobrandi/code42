/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:17:20 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 11:49:46 by bde-albu         ###   ########.fr       */
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

void	parse_type(t_format *flag, const char *format, int *index)
{
	if (format[*index] != '\0' && ft_strrchr("cspdiuxX%", format[*index]))
		flag->type = format[*index];
}
