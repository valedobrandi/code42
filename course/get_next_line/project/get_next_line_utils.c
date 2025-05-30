/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:02:18 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/22 15:24:17 by bde-albu         ###   ########.fr       */
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
