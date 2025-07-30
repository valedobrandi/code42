/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_mapping.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajolivie <ajolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:07:55 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/28 10:45:25 by ajolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	next_grid_line(t_cast_dda *t)
{
	if (t->ray_dx == 0)
		t->delta_dist_x = 1e30;
	else
		t->delta_dist_x = fabs(1.0 / t->ray_dx);
	if (t->ray_dy == 0)
		t->delta_dist_y = 1e30;
	else
		t->delta_dist_y = fabs(1.0 / t->ray_dy);
}

void	next_grid_boundary(t_cast_dda *t)
{
	double	ray_x_tile;
	double	ray_y_tile;

	ray_x_tile = t->ray_x / TILE_SIZE;
	ray_y_tile = t->ray_y / TILE_SIZE;
	if (t->ray_dx < 0)
		t->side_dist_x = (ray_x_tile - t->map_x) * t->delta_dist_x;
	else
		t->side_dist_x = (t->map_x + 1.0 - ray_x_tile) * t->delta_dist_x;
	if (t->ray_dy < 0)
		t->side_dist_y = (ray_y_tile - t->map_y) * t->delta_dist_y;
	else
		t->side_dist_y = (t->map_y + 1.0 - ray_y_tile) * t->delta_dist_y;
}

void	ray_travel_distance(int *hit, int *side,
			t_cast_dda *t, t_settings *st)
{
	while (*hit == 0)
	{
		if (t->side_dist_x < t->side_dist_y)
		{
			t->side_dist_x += t->delta_dist_x;
			t->map_x += t->step_x;
			*side = 0;
		}
		else
		{
			t->side_dist_y += t->delta_dist_y;
			t->map_y += t->step_y;
			*side = 1;
		}
		if (st->scheme->map[t->map_y].path[t->map_x] == '1')
			*hit = 1;
	}
}

void	texture_mapping(int side, t_dda_result *result, t_cast_dda *t)
{
	if (side == 0)
	{
		t->wall_x = (t->ray_y + t->raw_distance * t->ray_dy);
		t->wall_x -= floor(t->wall_x);
		if (t->ray_dx < 0)
		{
			result->wall_direction = 2;
			t->wall_x = 1.0 - t->wall_x;
		}
		else
			result->wall_direction = 3;
	}
	else
	{
		t->wall_x = (t->ray_x + t->raw_distance * t->ray_dx);
		t->wall_x -= floor(t->wall_x);
		if (t->ray_dy > 0)
		{
			result->wall_direction = 0;
			t->wall_x = 1.0 - t->wall_x;
		}
		else
			result->wall_direction = 1;
	}
}
