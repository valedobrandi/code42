/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_schema.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajolivie <ajolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:48:42 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/28 10:55:58 by ajolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <math.h>

static void	initiate_player(char *pixel, int x, int y, t_settings *st)
{
	st->player.py = y;
	st->player.px = x;
	if (pixel[x] == 'N')
		st->player.pa = PI / 2;
	if (pixel[x] == 'S')
		st->player.pa = 3 * PI / 2;
	if (pixel[x] == 'W')
		st->player.pa = 0.0;
	if (pixel[x] == 'O')
		st->player.pa = PI;
	st->player.pdx = cos(st->player.pa) * MOVE_SPEED;
	st->player.pdy = sin(st->player.pa) * MOVE_SPEED;
}

static int	get_player(char *pixel, int x, int y, t_settings *st)
{
	if (pixel[x] == 'N' || pixel[x] == 'S' || pixel[x] == 'W'
		|| pixel[x] == 'O')
	{
		if ((int)st->player.py != -1 || (int)st->player.px != -1)
			return (ft_putendl_fd("Error: too many players", 2), 1);
		else
			initiate_player(pixel, x, y, st);
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

int	validate_scheme(t_map *schema, t_settings *st)
{
	int	y;
	int	x;

	y = 0;
	while (y < schema->height)
	{
		x = 0;
		while (x < schema->map[y].length)
		{
			if (get_player(schema->map[y].path, x, y, st)
				|| validate_character(schema->map[y].path, x))
				return (1);
			x++;
		}
		y++;
	}
	if (st->player.px == -1 || st->player.py == -1)
		return (ft_putendl_fd("Error: no player", 2), 1);
	return (0);
}
