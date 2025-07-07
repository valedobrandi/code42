#include "cub3d.h"
#include <mlx.h>
#include <math.h>

static void draw_single_pixel(int x, int y, t_settings *st, unsigned int color)
{
    int offset = y * st->addr.line_len + x * (st->addr.bpp / 8);
    *(unsigned int *)(st->img_data + offset) = color;
}

void render3d(t_settings **st)
{
    int i = 0;
    int screen_width = 800;   // Adjust
    int screen_height = 600;  // Adjust

    double max_distance = 15.0;

    while (i < screen_width)
    {
        double step = 0.0;

        double angle_offset = ((double)i / (double)screen_width - 0.5) * FFOV;
        double ray_angle = (*st)->player.pa + angle_offset;

        double ray_dx = cos(ray_angle);
        double ray_dy = sin(ray_angle);

        while (step < max_distance)
        {
            double ray_x = (*st)->player.px + ray_dx * step;
            double ray_y = (*st)->player.py + ray_dy * step;
            if ((*st)->scheme->map[(int)ray_y].path[(int)ray_x] == '1')
                break ;
            step += 0.01;
        }
        
        double wall_distance = step * cos(angle_offset);

        double wall_heigth = (screen_height / wall_distance) * 0.5;

        int wall_start = (screen_height / 2) - (wall_heigth / 2);
        int wall_end = (screen_height / 2) + (wall_heigth / 2);

        if (wall_start < 0) wall_start = 0;
        if (wall_end >= screen_height) wall_end = screen_height - 1;

        int y = 0;
        while (y < screen_height)
        {
            int color;

            if (y < wall_start)
                color = 0x436775;
            else if (y >= wall_start && y <= wall_end)
                color = 0x412312;
            else 
                color = 0x228B22;
            draw_single_pixel(i, y, *st, color);
            y++;
        }
        i++;
    }
}

void	drawrays3d(t_settings *st)
{
	double	step;
	double	max_distance;
	double	ray_x;
	double	ray_y;


	max_distance = 15.0;
    int i = 0;
    while (i < 60)
    {
	    step = 0.0;

        double angle_offset = (i / 59.0) * FFOV - HFOV;
        double ray_angle = st->player.pa + angle_offset;
        double ray_dx = cos(ray_angle);
        double ray_dy = sin(ray_angle);

        while (step < max_distance)
        {
            ray_x = st->player.px + ray_dx * step;
            ray_y = st->player.py + ray_dy * step;
            // Check if ray hits a wall
            if (st->scheme->map[(int)ray_y].path[(int)ray_x] == '1')
                break ;
            int pixel_x = (int)(ray_x * TILE_SIZE);
            int pixel_y = (int)(ray_y * TILE_SIZE);
            // Draw pixel at ray position
            draw_single_pixel(pixel_x, pixel_y, st, 0x00FF00);
            // cyan color for the ray
            step += 0.005;
        }
        i++;
    }
}
