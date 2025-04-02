/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:44:19 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/02 13:31:37 by bde-albu         ###   ########.fr       */
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

static int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
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

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t end;
	char *ptr;

	while (*s1 && ft_strrchr(set, *s1))
		s1++;
	if (*s1 == '\0')
		return (ft_strdup(""));
	end = ft_strlen((char *)s1) - 1;
	while (end > 0 && ft_strrchr(set, s1[end]))
		end--;
	ptr = (char *)malloc((end + 2) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, end + 1);
	return (ptr);
}