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
			offset = (screen_y * st->addr.line_len) + (screen_x * (st->addr.bpp / 8));
			*(unsigned int *)(st->img_data + offset) = color;
		}
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
	/* set_pixels(st);
	draw_pixel((int) st->player.py, (int) st->player.px, st, 0xFF0000);
	drawrays3d(st); */

    render3d(&st);
	mlx_put_image_to_window(st->mlx, st->mlx_win, st->img, 0, 0);
}
