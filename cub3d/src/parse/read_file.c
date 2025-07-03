/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:31:28 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/03 11:46:04 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

static int	validate_entry(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (1);
	return (0);
}

static int	texture_rgb(int *i, char *line, t_list **rgb_texture, int *entries)
{
	while (line[*i] && !ft_isalnum(line[*i]))
		(*i)++;
	if (validate_entry(&line[*i]))
	{
		parse_texture_rgb(&line[*i], rgb_texture);
		(*entries)++;
	}
	return (0);
}

static int	read_map(int fd, t_map *schema)
{
	char	*line;
	int		schema_index;
	int		i;

	schema_index = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (line[i] && (is_space(line[i]) || line[i] == '\n'))
			i++;
		if (line[i] == '\0')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (line[i] != '1')
			return (free(line), 1);
		extract_map(line, &schema->map[schema_index]);
		schema_index++;
		schema->height = schema_index;
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

static int	read_texture_rgb(int fd, t_list **rgb_texture, int *entries)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		texture_rgb(&i, line, rgb_texture, entries);
		free(line);
		if (*entries == 6)
			break ;
		line = get_next_line(fd);
	}
	return (0);
}

int	read_file(char *path, t_list **rgb_texture, t_map *schema)
{
	int	entries;
	int	fd;

	entries = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error: opening file", 2), 1);
	read_texture_rgb(fd, rgb_texture, &entries);
	if (read_map(fd, schema))
		ft_putendl_fd("Error: bad map", 2);
	close(fd);
	if (entries != 6)
		ft_putendl_fd("Error: bad textute/rgb", 2);
	return (0);
}
