/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:10:39 by ajolivie          #+#    #+#             */
/*   Updated: 2025/07/28 11:54:26 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <math.h>
#include <mlx.h>

int	is_wall(t_settings *st, double world_x, double world_y)
{
	int	tile_x;
	int	tile_y;

	tile_x = (int)(world_x / TILE_SIZE);
	tile_y = (int)(world_y / TILE_SIZE);
	if (st->scheme->map[tile_y].path[tile_x] == '1')
		return (1);
	return (0);
}

int	collides(double x, double y, double margin, t_settings *st)
{
	double	corner_margin;

	if (is_wall(st, x + margin, y) || is_wall(st, x - margin, y)
		|| is_wall(st, x, y + margin) || is_wall(st, x, y - margin))
		return (1);
	corner_margin = margin * 0.5;
	if (is_wall(st, x + corner_margin, y + corner_margin)
		|| is_wall(st, x - corner_margin, y + corner_margin)
		|| is_wall(st, x + corner_margin, y - corner_margin)
		|| is_wall(st, x - corner_margin, y - corner_margin))
		return (1);
	return (0);
}

void	forward(t_settings *st)
{
	double	next_px;
	double	next_py;

	next_px = st->player.px + cos(st->player.pa) * MOVE_SPEED;
	next_py = st->player.py + sin(st->player.pa) * MOVE_SPEED;
	if (!collides(next_px, st->player.py, (TILE_SIZE * 0.2), st))
		st->player.px = next_px;
	if (!collides(st->player.px, next_py, (TILE_SIZE * 0.2), st))
		st->player.py = next_py;
}

void	backward(t_settings *st)
{
	double	next_px;
	double	next_py;

	next_px = st->player.px - cos(st->player.pa) * MOVE_SPEED;
	next_py = st->player.py - sin(st->player.pa) * MOVE_SPEED;
	if (!collides(next_px, st->player.py, (TILE_SIZE * 0.2), st))
		st->player.px = next_px;
	if (!collides(st->player.px, next_py, (TILE_SIZE * 0.2), st))
		st->player.py = next_py;
}
