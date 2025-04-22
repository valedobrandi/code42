/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:15:50 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/22 16:51:15 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	reader_file(int fd, char *buffer, int bytes_reader)
{
	char	*stash;

	stash = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	;
	if (!stash)
		return (NULL);
	while (bytes_reader > 0 && !ft_strchr(stash, '\n'))
	{
		bytes_reader = read(fd, buffer, BUFFER_SIZE);
		if (bytes_reader == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bytes_reader] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (stash);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		index;

	if (!buffer || !buffer[0])
		return (NULL);
	index = 0;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	if (buffer[index] == '\n')
		index++;
	line = malloc((index + 1) * sizeof(char));
	if (!line)
		return (NULL);
	index = 0;
	while (buffer[index] && buffer[index] != '\n')
	{
		line[index] = buffer[index];
		index++;
	}
	if (buffer[index] == '\n')
		line[index++] = '\n';
	line[index] = '\0';
	return (line);
}

char	*update(char *buffer)
{
	int		index;
	char	*resize;

	index = 0;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	if (!buffer[index])
	{
		free(buffer);
		return (NULL);
	}
	index++;
	resize = malloc()
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			bytes_reader;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_reader = 1;
	buffer = reader_file(fd, buffer, bytes_reader);
	line = get_line(buffer);
	buffer = update(buffer);
}
