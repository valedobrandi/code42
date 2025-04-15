/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:15:50 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/14 17:45:30 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_get_next_line_static	file;
	t_get_next_line_vars			vars;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file.index = 0;
	vars.bytes_read = 0;
	while (1)
	{
		vars.bytes_read = read_file(fd, file, vars);
		while (file.index < vars.bytes_read)
		{
			vars.line = malloc(vars.total_buffer + 2);
			if (!vars.line)
				return (NULL);
			vars.line = append_line(file, vars);
		}
	}
}

/* 	static t_get_next_line	*file;
	if (fd < 0 || BUFFER_SIZE <= 0 || init_struct(&file))
		return (NULL);
	line = NULL;
	while (1)
	{
		check = read_file(fd, file);
		if (check == -1 || (check == 0 && !line))
		{
			free(file);
			file = NULL;
			return(NULL);
		}
		if (check == 0 && line)
			return (line);
		while (file->index < file->bytes_read)
		{
			line = append_line(file, line);
			if (callback_new_line(file))
				return (line);
			file->index++;
		}
	}
	return (NULL); */
