#include "cub3d.h"
#include "libft.h"
#include <mlx.h>
#include <math.h>

static void load_texture_addr(int wall_direction, t_image_addr *addr, t_settings **st)
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

static void wall_start_end(t_raycast *cast, double raw_distance, int i, t_settings **st)
{
    double ray_offset = cast->ray_angle - (*st)->player.pa;
    double corrected_distance = raw_distance * cos(ray_offset);
    if (corrected_distance < 0.01)
        corrected_distance = 0.01;
    cast->wall_distance = corrected_distance;
    cast->wall_start = (HEIGTH / 2) - ((double)((HEIGTH / cast->wall_distance) * 0.5) / 2);
    cast->wall_end = (HEIGTH / 2) + ((double)((HEIGTH / cast->wall_distance) * 0.5) / 2);
    if (cast->wall_start < 0)
        cast->wall_start = 0;
    if (cast->wall_end >= HEIGTH)
        cast->wall_end = HEIGTH - 1;
}

static void load_texture(t_raycast *cast, t_dda_result ray, t_image_addr addr)
{
    // calculate texture X cordinate
    cast->tex_x = (int)(ray.wall_x * addr.width);
    if (cast->tex_x < 0)
        cast->tex_x = 0;
    if (cast->tex_x >= addr.width)
        cast->tex_x = addr.width - 1;
    // flip texture for proper orientation
    if (ray.wall_side == 0) // vertical wall hit (N/S)
    {
        if (ray.wall_direction == 2) // east wall
            cast->tex_x = addr.width - cast->tex_x - 1;
    }
    else // horizontal wall hit (E/W)
    {
        if (ray.wall_direction == 0) // north wall
            cast->tex_x = addr.width - cast->tex_x - 1;
    }
    // texture step calculation
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
    while (y < HEIGTH)
    {
        if (y < cast->wall_start)
            color = 0x436775;
        else if (y >= cast->wall_start && y <= cast->wall_end)
        {
            tex_y = (int)cast->tex_pos;
            tex_y = tex_y % addr.height;
            if (tex_y < 0)
                tex_y += addr.height;
            ;
            cast->tex_pos += cast->tex_step;
            offset = tex_y * addr.line_len + cast->tex_x * (addr.bpp / 8);
            color = *(unsigned int *)(addr.data + offset);
        }
        else
            color = 0x228B22;
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
        cast.ray_angle = (*st)->player.pa + (((double)i / (double)WIDTH - 0.5) * FFOV);
        ray = cast_dda_ray(*st, cast.ray_angle);
        load_texture_addr(ray.wall_direction, &addr, st);
        wall_start_end(&cast, ray.raw_distance, i, st);
        load_texture(&cast, ray, addr);
        render(&cast, addr, st, i);
        i++;
    }
}
