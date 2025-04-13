/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:02:18 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/11 13:04:02 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_findchr(char *s, int c)
{
    size_t  count;

    count = 0;
	while (*s != '\0')
	{
		if (*s == c)
			return (count);
		s++;
        count++;
	}
	if (c == '\0')
		return (0);
	return (0);
}

size_t	ft_strlcpy(char *dst, char * src, size_t dsize)
{
	size_t	i;
	size_t	j;

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

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

size_t findchr(char *str, int c, size_t n)
{
	size_t  index;

	index = 0;
	while (n > 0)
	{
        index++;
		if ((unsigned char)c == *str)
			return (index);
		str++;
		n--;
	}
	return (-1);
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}