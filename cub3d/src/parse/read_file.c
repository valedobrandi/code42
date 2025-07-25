/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:31:28 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/25 10:14:34 by bde-albu         ###   ########.fr       */
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
	int		start_index;

	line = get_next_line(fd);
	schema->height = 0;
	while (line != NULL)
	{
		start_index = 0;
		while (line[start_index] && (is_space(line[start_index])))
			start_index++;
		if (line[start_index] == '\0' || line[start_index] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		extract_map(line, &schema->map[schema->height]);
		schema->height++;
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
		if (*entries == 6)
		{
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	read_file(char *path, t_settings *st)
{
	int	entries;
	int	fd;

	entries = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error: opening file", 2), 1);
	read_texture_rgb(fd, &st->rgb_texture, &entries);
	read_map(fd, st->scheme);
	close(fd);
	if (entries != 6)
		return (ft_putendl_fd("Error: bad textute/rgb", 2), 1);
	if (validate_rgb(st->rgb_texture, st))
		return (ft_putendl_fd("Error: bad rgb format", 2), 1);
	if (validate_texture(st->rgb_texture))
		return (ft_putendl_fd("Error: opening texture", 2), 1);
	if (validate_scheme(st->scheme, st))
		return (1);
	if (fill_check(st->scheme, st->player))
		return (ft_putendl_fd("Error: spaces not closed\n", 2), 1);
	return (0);
}
