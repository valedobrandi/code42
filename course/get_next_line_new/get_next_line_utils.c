/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:02:18 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/22 16:02:03 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

char	*ft_relloc(char *line, int buffer, int index)
{
	char	*temp;

	temp = (char *)malloc((index + buffer + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	temp[0] = '\0';
	if (line)
	{
		ft_memcpy(temp, line, index);
		free(line);
	}
	return (temp);
}
static size_t	ft_strlen(const char *s)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*ptr;

	size_s1 = ft_strlen((char *)s1);
	size_s2 = ft_strlen((char *)s2);
	ptr = (char *)malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	*ptr = '\0';
	if (s1)
		ft_strcat(ptr, (char *)s1);
	if (s2)
		ft_strcat(ptr, (char *)s2);
	return (ptr);
}
