/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:30:40 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/03 11:43:23 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdlib.h>

int	allocate_schema(t_map **schema)
{
	*schema = malloc(sizeof(t_map));
	if (!*schema)
		return (1);
	(*schema)->map = malloc(sizeof(t_map_line) * BUFFER);
	if (!(*schema)->map)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_player player;
	t_list *rgb_texture;
	t_map *schema;

	(void)ac;
	ft_memset(&player, -1, sizeof(t_player));
	rgb_texture = NULL;
	allocate_schema(&schema);
	read_file(av[1], &rgb_texture, schema);
	validate_rgb(rgb_texture);
	validate_schema(schema, &player);
	fill_check(schema, player);
	ft_lstclear(&rgb_texture, free_entries);
	free_schema(schema);
	return (0);
}