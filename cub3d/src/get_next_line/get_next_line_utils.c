/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:02:18 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/25 14:42:11 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	size_src;
	size_t	size_dst;
	size_t	index;

	size_src = 0;
	while (src[size_src] != '\0')
		size_src++;
	size_dst = 0;
	while (dst[size_dst] != '\0')
		size_dst++;
	if (dsize <= size_dst)
		return (dsize + size_src);
	index = 0;
	while (index < (dsize - size_dst - 1) && src[index] != '\0')
	{
		dst[size_dst + index] = src[index];
		index++;
	}
	dst[index + size_dst] = '\0';
	return (size_dst + size_src);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

static char	*ft_strcat(char *dest, char *src)
{
	int	length;
	int	index;

	index = 0;
	length = ft_strlen(dest);
	while (src[index] != '\0')
	{
		dest[length] = src[index];
		index++;
		length++;
	}
	dest[length] = '\0';
	return (dest);
}

char	*static_ft_strjoin(char *s1, char *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*ptr;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	ptr = (char *)malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	*ptr = '\0';
	if (s1)
		ft_strcat(ptr, s1);
	if (s2)
		ft_strcat(ptr, s2);
	free(s1);
	return (ptr);
}
