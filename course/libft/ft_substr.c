/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:07:55 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/04 14:50:44 by bde-albu         ###   ########.fr       */
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

static size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len || len == 0)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s + start, len);
	return (ptr);
}
