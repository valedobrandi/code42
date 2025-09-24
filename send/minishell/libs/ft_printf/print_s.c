/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:59:15 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 11:59:08 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlcpy(char *dst, const char *restrict src, int dsize)
{
	int	i;
	int	j;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (dsize == 0)
		return (i);
	j = 0;
	while (j < (dsize - 1) && src[j] != '\0')
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}

static int	ft_strlen(const char *s)
{
	int	count;

	if (!s)
		return (6);
	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

int	print_s(t_format flag, char *print)
{
	int		length;
	char	*buffer;
	int		is_malloc;

	is_malloc = 0;
	length = ft_strlen(print);
	if (flag.has_precision && flag.precision < length)
	{
		buffer = (char *)malloc((flag.precision + 1) * (sizeof(char)));
		if (!buffer)
			return (0);
		ft_strlcpy(buffer, print, flag.precision + 1);
		length = ft_strlen(buffer);
		is_malloc = 1;
	}
	else
		buffer = print;
	print_justify_rigth(flag, &length);
	print_padding(flag, &length);
	ft_putstr(buffer, 1);
	print_justify_left(flag, &length);
	if (is_malloc)
		free(buffer);
	return (length);
}
