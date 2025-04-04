/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:44:19 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/04 14:57:45 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	ptr = (char *)malloc((index + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		ptr[index] = s[index];
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}

static size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

static size_t	ft_strlcpy(char *dst, const char *restrict src, size_t dsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (dsize == 0)
		return (i);
	j = 0;
	while (j < dsize && src[j] != '\0')
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}

static int	ft_strcmp(const char *str, int c)
{
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		if (*str == (char)c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	char	*ptr;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	while (*s1 && ft_strcmp(set, *s1))
		s1++;
	if (*s1 == '\0')
		return (ft_strdup(""));
	end = ft_strlen((char *)s1) - 1;
	while (end > 0 && ft_strcmp(set, s1[end]))
		end--;
	ptr = (char *)malloc((end + 2) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, end + 1);
	return (ptr);
}
