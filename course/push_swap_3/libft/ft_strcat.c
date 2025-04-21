/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:30:25 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/04 11:04:01 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strcat(char *dest, char *src)
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
