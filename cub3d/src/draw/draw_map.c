/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:05:11 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/04 16:01:01 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>

#define TILE_SIZE 5

void	draw_pixel(int height, int width, t_settings *st, unsigned int color)
{
	int	screen_x;
	int	screen_y;
	int	offset;

	for (int py = 0; py < TILE_SIZE; py++)
	{
		for (int px = 0; px < TILE_SIZE; px++)
		{
			screen_x = width * TILE_SIZE + px;
			screen_y = height * TILE_SIZE + py;
			offset = (screen_y * st->addr.line_len) + (screen_x * (st->addr.bpp
						/ 8));
			*(unsigned int *)(st->img_data + offset) = color;
		}
	}
}

void draw_single_pixel(int x, int y, t_settings *st, unsigned int color)
{
    int offset = y * st->addr.line_len + x * (st->addr.bpp / 8);
    *(unsigned int *)(st->img_data + offset) = color;
}
void	castray(t_settings *st)
{
	double	t;
	double	step;
	double	max_distance;
	double	ray_x;
	double	ray_y;

	t = 0;
	step = 0.01;
	max_distance = 15.0;
	while (t < max_distance)
	{
		ray_x = st->player.pos_x + st->player.dir_x * t;
		ray_y = st->player.pos_y + st->player.dir_y * t;
		// Check if ray hits a wall
		if (st->scheme->map[(int)ray_y].path[(int)ray_x] == '1')
			break ;
		int pixel_x = (int)(ray_x * TILE_SIZE);
		int pixel_y = (int)(ray_y * TILE_SIZE);
		// Draw pixel at ray position
		draw_single_pixel(pixel_x, pixel_y, st, 0x00FF00);
		// cyan color for the ray
		t += step;
	}
}

void	set_pixels(t_settings *st)
{
	int	height;
	int	width;

	height = 0;
	while (height < st->scheme->height)
	{
		width = 0;
		while (width < st->scheme->map[height].length)
		{
			if (st->scheme->map[height].path[width] == '1')
				draw_pixel((int) height, (int) width, st, 0x00FF00);
			width++;
		}
		height++;
	}
}
void	init_window(t_settings *st)
{
	set_pixels(st);
	draw_pixel((int) st->player.pos_y, (int) st->player.pos_x, st, 0xFF0000);
	castray(st);
	mlx_put_image_to_window(st->mlx, st->mlx_win, st->img, 0, 0);
}
