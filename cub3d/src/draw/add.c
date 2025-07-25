#include "cub3d.h"
#include "libft.h"
#include <mlx.h>
#include <math.h>

static void next_grid_line(t_cast_dda *t)
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

static void next_grid_boundary(t_cast_dda *t)
{
    if (t->ray_dx < 0)
        t->side_dist_x = (t->ray_x - t->map_x) * t->delta_dist_x;
    else
        t->side_dist_x = (t->map_x + 1.0 - t->ray_x) * t->delta_dist_x;
    if (t->ray_dy < 0)
        t->side_dist_y = (t->ray_y - t->map_y) * t->delta_dist_y;
    else
        t->side_dist_y = (t->map_y + 1.0 - t->ray_y) * t->delta_dist_y;
}

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
    t->map_x = (int)floor(t->ray_x);
    t->map_y = (int)floor(t->ray_y);
}

static void ray_travel_distance(int *hit, int *side, t_cast_dda *t, t_settings *st)
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

static double raw_distance(int side, t_cast_dda *t)
{
    if (side == 0)
        return (t->side_dist_x - t->delta_dist_x);
    else
        return (t->side_dist_y - t->delta_dist_y);
}

static void texture_mapping(int side, t_dda_result *result, t_cast_dda *t)
{
    if (side == 0)
    {
        t->wall_x = (t->ray_y + t->raw_distance * t->ray_dy) - floor((t->ray_y + t->raw_distance * t->ray_dy));
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
        t->wall_x = (t->ray_x + t->raw_distance * t->ray_dx) - floor((t->ray_x + t->raw_distance * t->ray_dx));
        if (t->ray_dy > 0)
        {
            result->wall_direction = 0;
            t->wall_x = 1.0 - t->wall_x;
        }
        else
            result->wall_direction = 1;
    }
}

static void save_add(int side, t_dda_result *result, t_cast_dda *t)
{
    result->raw_distance = raw_distance(side, t);
    result->hit_wall = 1;
    result->wall_side = side;
    result->wall_x = t->wall_x;
    result->map_x = t->map_x;
    result->map_y = t->map_y;
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