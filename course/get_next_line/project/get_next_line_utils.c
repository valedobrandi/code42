/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:02:18 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/14 17:46:29 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
int	init_struct(t_get_next_line **file)
{
	if (*file == NULL)
	{
		*file = malloc(sizeof(t_get_next_line));
		if (*file == NULL)
			return (1);
		(*file)->index = 0;
		(*file)->bytes_read = 0;
	}
	(*file)->total_buffer = 0;
	(*file)->buff = NULL;
	return (0);
}

int	read_file(int fd, t_get_next_line_static file, t_get_next_line_vars vars)
{
	if (file.index >= vars.bytes_read)
		vars.bytes_read = read(fd, file.buffer, BUFFER_SIZE);
	return (vars.bytes_read);
}

void	copy_line_to_buffer(char *line, t_get_next_line *file)
{
	int	index;

	index = 0;
	if (line)
	{
		while (index < file->total_buffer)
		{
			file->buff[index] = line[index];
			index++;
		}
		free(line);
	}
}

int	callback_new_line(t_get_next_line *file)
{
	if (file->buffer[file->index] == '\n')
	{
		file->index++;
		return (1);
	}
	return (0);
}

char	*append_line(t_get_next_line_static file, t_get_next_line_vars vars)
{
	copy_line_to_buffer(line, file);
	file->buff[file->total_buffer] = file->buffer[file->index];
	file->buff[file->total_buffer + 1] = '\0';
	line = file->buff;
	file->total_buffer++;
	return (line);
}

/* 	char	*new_buff;
	int		i;

	new_buff = malloc(file->total_buffer + 2);
	if (!new_buff)
		return (NULL);
	i = 0;
	if (line)
	{
		while (i < file->total_buffer)
		{
			new_buff[i] = line[i];
			i++;
		}
		free(line);
	}
	new_buff[i++] = file->buffer[file->index];
	new_buff[i] = '\0';
	file->total_buffer++;
	return (line); */
