/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:15:50 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/10 15:50:28 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	index;

	index = 0;
	while (src[index] != '\0' && index < n)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*buffer_line(char *buffer, int bsize)
{
	char	*str;

	str = (char *)malloc((bsize + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strncpy(str, buffer, bsize);
	return (str);
}

char	*get_next_line(int fd)
{
	char		buffer[4096];
	char		*srt;
	int			bytes_read;
	static int	index = 0;
	int			bsize;

	bsize = 0;
	bytes_read = read(fd, buffer, sizeof(buffer));
	if (bytes_read < 0)
		return (NULL);
	while (buffer[index] != '\0')
	{
		if (buffer[index] == '\n')
		{
			srt = buffer_line(&buffer[index - bsize], bsize + 1);
			bsize = 0;
			index++;
			return (srt);
		}
		index++;
		bsize++;
	}
	return (NULL);
}
