/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_schema.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:48:42 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/04 15:25:51 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static int	get_validate_player(char *pixel, int x, int y, t_player *player)
{
	if (pixel[x] == 'N' || pixel[x] == 'S' || pixel[x] == 'W'
		|| pixel[x] == 'O')
	{
		if ((int) (*player).py != -1 || (int) (*player).px != -1)
			return (ft_putendl_fd("Error: too many players", 2), 1);
		(*player).py = y;
		(*player).px = x;
	}
	return (0);
}

static int	validate_character(char *pixel, int x)
{
	if (pixel[x] != 'N' && pixel[x] != 'S' && pixel[x] != 'W' && pixel[x] != 'O'
		&& pixel[x] != '1' && pixel[x] != '0' && !is_space(pixel[x]))
		return (ft_putendl_fd("Error: bad mapping character", 2), 1);
	return (0);
}

int	validate_scheme(t_map *schema, t_player *player)
{
	int	y;
	int	x;

	y = 0;
	while (y < schema->height)
	{
		x = 0;
		while (x < schema->map[y].length)
		{
			if (get_validate_player(schema->map[y].path, x, y, player)
				|| validate_character(schema->map[y].path, x))
				return (1);
			x++;
		}
		y++;
	}
	if (player->px == -1 || player->py == -1)
		return (ft_putendl_fd("Error: no player", 2), 1);
	return (0);
}
