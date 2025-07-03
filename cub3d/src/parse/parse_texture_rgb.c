/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_rgb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:58:28 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/03 11:58:31 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdlib.h>

void	copy_data(t_entries **entries, char *find, char *table)
{
	char	*get_line;
	int		i;

	get_line = NULL;
	i = 1;
	if (!ft_strcmp(table, "F") || !ft_strcmp(table, "C"))
	{
		while (find && !ft_strncmp(find + i, " \t\r", 1))
			i++;
		if (ft_isdigit(find[i]))
			get_line = find + i;
	}
	else
		get_line = ft_strchr(find, '.');
	if (get_line)
		(*entries)->path = ft_strtrim(get_line, " \t\r\n");
	else
		(*entries)->path = NULL;
}

static t_entries	*extract_data(t_entries **entries, char *find, char *table)
{
	*entries = malloc(sizeof(t_entries));
	if (!*entries)
		return (NULL);
	ft_memset(*entries, 0, sizeof(t_entries));
	copy_data(entries, find, table);
	(*entries)->type = ft_strdup(table);
	return ((*entries));
}

static t_entries	*find_map_data(char *line)
{
	int			i;
	char		*find;
	char		**table;
	t_entries	*entries;

	entries = NULL;
	table = ft_split("NO SO WE EA F C", ' ');
	if (table == NULL)
		return (entries);
	i = 0;
	while (table[i])
	{
		find = ft_strchr(line, table[i][0]);
		if (find && !ft_strncmp(find, table[i], ft_strlen(table[i]) - 1))
		{
			extract_data(&entries, find, table[i]);
			break ;
		}
		i++;
	}
	free_array(table);
	return (entries);
}

int	parse_texture_rgb(char *line, t_list **rgb_texture)
{
	t_entries	*find;

	find = find_map_data(line);
	if (find)
		ft_lsadd_front(rgb_texture, ft_lstnew(find));
	return (0);
}
