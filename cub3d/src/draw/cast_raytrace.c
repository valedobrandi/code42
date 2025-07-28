#include "cub3d.h"
#include "libft.h"
#include <math.h>
#include <mlx.h>

static void load_texture_addr(int wall_direction, t_image_addr *addr,
                              t_settings **st)
{
    if (wall_direction == 0)
        *addr = (*st)->mlx_texture.north;
    if (wall_direction == 1)
        *addr = (*st)->mlx_texture.south;
    if (wall_direction == 2)
        *addr = (*st)->mlx_texture.east;
    if (wall_direction == 3)
        *addr = (*st)->mlx_texture.west;
}

static void wall_start_end(t_raycast *cast, double raw_distance, int i,
                           t_settings **st)
{
    double ray_offset;
    double corrected_distance;
    double wall_height;

    ray_offset = cast->ray_angle - (*st)->player.pa;
    corrected_distance = raw_distance * cos(ray_offset);
    if (corrected_distance < 0.5)
        corrected_distance = 0.5;
    cast->wall_distance = corrected_distance;
    wall_height = (HEIGHT) / cast->wall_distance;
    cast->wall_start = (HEIGHT / 2) - (wall_height / 2);
    cast->wall_end = (HEIGHT / 2) + (wall_height / 2);
    if (cast->wall_start < 0)
        cast->wall_start = 0;
    if (cast->wall_end >= HEIGHT)
        cast->wall_end = HEIGHT - 1;
}

static void load_texture(t_raycast *cast, t_dda_result ray, t_image_addr addr)
{
    // calculate texture X cordinate
    cast->tex_x = (int)(ray.wall_x * addr.width);
    cast->tex_step = (double)addr.height / (double)(cast->wall_end - cast->wall_start + 1);
    cast->tex_pos = 0.0;
}

static void render(t_raycast *cast, t_image_addr addr, t_settings **st, int i)
{
    int y;
    int tex_y;
    int offset;
    unsigned int color;

    y = 0;
    while (y < HEIGHT)
    {
        if (y < cast->wall_start)
            color = ((*st)->rbg_c[0] << 16) | ((*st)->rbg_c[1] << 8) | (*st)->rbg_c[2];
        else if (y >= cast->wall_start && y <= cast->wall_end)
        {
            tex_y = (int)cast->tex_pos;
            if (tex_y < 0)
                tex_y += addr.height;
            cast->tex_pos += cast->tex_step;
            offset = tex_y * addr.line_len + cast->tex_x * (addr.bpp / 8);
            color = *(unsigned int *)(addr.data + offset);
        }
        else
            color = ((*st)->rbg_f[0] << 16) | ((*st)->rbg_f[1] << 8) | (*st)->rbg_f[2];
        offset = y * (*st)->addr.line_len + i * ((*st)->addr.bpp / 8);
        *(unsigned int *)((*st)->img_data + offset) = color;
        y++;
    }
}

void raytracer_render(t_settings **st)
{
    t_dda_result ray;
    t_image_addr addr;
    t_raycast cast;
    int i;

    i = 0;
    while (i < WIDTH)
    {
        double pixel_ratio = (double)i / (double)WIDTH;
        double centered_ratio = pixel_ratio - 0.5;
        double angle_offset = centered_ratio * FFOV;
        cast.ray_angle = (*st)->player.pa + angle_offset;
        ray = cast_dda_ray(*st, cast.ray_angle);
        load_texture_addr(ray.wall_direction, &addr, st);
        wall_start_end(&cast, ray.raw_distance, i, st);
        load_texture(&cast, ray, addr);
        render(&cast, addr, st, i);
        i++;
    }
}
