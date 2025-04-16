/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:15:50 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/16 11:32:44 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	reader(int fd, t_get_next_line_static *file, int *bytes_read)
{
	if (file->index >= *bytes_read)
	{
		*bytes_read = read(fd, file->buffer, BUFFER_SIZE);
		file->index = 0;
	}
	return (*bytes_read);
}

int	init(t_get_next_line_vars *vars)
{
	vars->index = 0;
	vars->buff = 12;
	vars->bytes_read = 0;
	vars->line = (char *)malloc(vars->buff * (sizeof(char)));
	if (vars->line == NULL)
		return (1);
	(vars->line)[0] = '\0';
	return (0);
}

int	allocate_line(t_get_next_line_vars *vars)
{
	int	increment;

	if (vars->index + 2 >= vars->buff)
	{
		increment = vars->buff * 2;
		vars->line = ft_relloc(vars->line, increment , vars->index);
		if (vars->line == NULL)
		return (1);
	    vars->buff = increment;
	}
	return (0);
}

int	get_line(char *buffer, int *file_index, t_get_next_line_vars *vars)
{
	if (allocate_line(vars))
		return (1);
	vars->line[vars->index] = buffer[*file_index];
	vars->line[vars->index + 1] = '\0';
	(*file_index)++;
	vars->index++;
	return (0);
}

char	*get_next_line(int fd)
{
	static t_get_next_line_static	file;
	t_get_next_line_vars			vars;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (init(&vars))
		return (NULL);
	while (1)
	{
		if (reader(fd, &file, &vars.bytes_read) == 0)
			break ;
		while (file.index < vars.bytes_read)
		{
			if (get_line(file.buffer, &file.index, &vars))
				return (NULL);
			if (file.buffer[file.index - 1] == '\n')
				return (vars.line);
		}
	}
	if (vars.index > 0)
		return (vars.line);
	free(vars.line);
	return (NULL);
}
