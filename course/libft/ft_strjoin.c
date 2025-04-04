/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:15:54 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/04 14:08:38 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

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
