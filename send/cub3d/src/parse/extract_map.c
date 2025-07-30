/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajolivie <ajolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:39:54 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/28 10:52:40 by ajolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

static int	line_length(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

int	extract_map(char *line, t_map_line *schema)
{
	int	i;
	int	length;

	i = 0;
	length = line_length(line);
	schema->length = length;
	schema->path = malloc(sizeof(char *) * (length + 1));
	if (!schema->path)
		return (1);
	while (line[i] && line[i] != '\n')
	{
		schema->path[i] = line[i];
		i++;
	}
	schema->path[i] = '\0';
	return (0);
}
