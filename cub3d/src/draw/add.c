/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:10:13 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/25 12:12:30 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <mlx.h>
#include <math.h>

static void ray_direction(t_cast_dda *t)
{
    if (t->ray_dx < 0)
        t->step_x = -1;
    else
        t->step_x = 1;
    if (t->ray_dy < 0)
        t->step_y = -1;
    else
        t->step_y = 1;
}

static void initial_state(t_settings *st, t_cast_dda *t, double ray_angle)
{
    t->ray_dx = cos(ray_angle);
    t->ray_dy = sin(ray_angle);
    t->ray_x = st->player.px;
    t->ray_y = st->player.py;
    t->map_x = (int)(t->ray_x / TILE_SIZE);
	t->map_y = (int)(t->ray_y / TILE_SIZE);
}

static double raw_distance(int side, t_cast_dda *t)
{
    double dist;
	if (side == 0)
	  dist = (t->side_dist_x - t->delta_dist_x);
	else
	  dist = (t->side_dist_y - t->delta_dist_y);
	return (dist * TILE_SIZE);
}

static void save_add(int side, t_dda_result *result, t_cast_dda *t)
{
	result->hit_wall = 1;
    result->wall_side = side;
    result->wall_x = t->wall_x;
    result->map_x = t->map_x;
    result->map_y = t->map_y;
    result->raw_distance = raw_distance(side, t);
    result->hit_x = (t->ray_x + raw_distance(side, t) * t->ray_dx);
    result->hit_y = (t->ray_y + raw_distance(side, t) * t->ray_dy);
}

t_dda_result cast_dda_ray(t_settings *st, double ray_angle)
{
    t_dda_result result;
    t_cast_dda t;
    int hit;
    int side;

    hit = 0;
    ft_memset(&result, 0, sizeof(t_dda_result));
    initial_state(st, &t, ray_angle);
    next_grid_line(&t);
    next_grid_boundary(&t);
    ray_direction(&t);
    ray_travel_distance(&hit, &side, &t, st);
    if (hit)
    {
        t.raw_distance = raw_distance(side, &t);
        texture_mapping(side, &result, &t);
        if (t.wall_x < 0.0)
            t.wall_x = 0.0;
        if (t.wall_x >= 1.0)
            t.wall_x = 1.0 - 1e-6;
        save_add(side, &result, &t);
    }
    return (result);
}
