/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:15:50 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/25 14:52:04 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	index;

	index = 0;
    if (s == NULL)
        return (NULL);
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

char	*store_buffer(int fd, char *buffer, int bytes_reader)
{
	char	*buffer_t;

	buffer_t = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer_t)
		return (NULL);
	while (bytes_reader > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_reader = read(fd, buffer_t, BUFFER_SIZE);
		if (bytes_reader == -1)
		{
			free(buffer);
			free(buffer_t);
			return (NULL);
		}
		buffer_t[bytes_reader] = '\0';
		buffer = static_ft_strjoin(buffer, buffer_t);
		if (!buffer)
		{
			free(buffer_t);
			return (NULL);
		}
	}
	free(buffer_t);
	return (buffer);
}

char	*get_line(char *buffer)
{
	int		index;
	char	*line;

	index = 0;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	if (buffer[index] == '\n')
		index++;
    if (index == 0)
    {
        return (NULL);
    }
	line = malloc((index + 1) * sizeof(char));
	if (line == NULL)
        return (NULL);
	*line = '\0';
	ft_strlcat(line, buffer, index + 1);
	return (line);
}

char	*update_buffer(char *buffer)
{
	char	*line;
	int		index;

	index = 0;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	if (buffer[index] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	if (buffer[index] == '\n')
		index++;
	line = ft_strdup(buffer + index);
	if (line == NULL)
		return (NULL);
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			bytes_reader;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_reader = 1;
	buffer = store_buffer(fd, buffer, bytes_reader);
	if (!buffer)
		return (NULL);
	if (buffer[0] == '\0')
		return (free(buffer), NULL);
	line = get_line(buffer);
	buffer = update_buffer(buffer);
	return (line);
}
