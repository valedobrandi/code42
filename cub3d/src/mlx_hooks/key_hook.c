/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:31:31 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/04 15:57:05 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <mlx.h>
#include <stdio.h>

#define PI 3.14159265358979323846

double	degrees_to_radians(double degrees)
{
	return (degrees * (PI / 180.0));
}

void	reset_image(t_settings *st)
{
	int	height;
	int	width;

	height = 0;
	while (height < st->scheme->height)
	{
		width = 0;
		while (width <= st->scheme->map[height].length)
		{
			draw_pixel((int) height, (int) width, st, 0x000000);
			width++;
		}
		height++;
	}
}

void	backward(t_settings *st)
{
	reset_image(st);
	set_pixels(st);
	st->player.pos_y -= st->player.dir_y * 0.05;
	st->player.pos_x -= st->player.dir_x * 0.05;
	printf("backward pos_y - %f dir_y - %f\n", st->player.pos_y, st->player.dir_y);
	printf("backward pos_x - %f dir_x - %f\n", st->player.pos_x, st->player.dir_x);
	printf("----\n");
	castray(st);
	draw_pixel((int)st->player.pos_y, (int)st->player.pos_x, st, 0xFF0000);
	mlx_put_image_to_window(st->mlx, st->mlx_win, st->img, 0, 0);
}

void	forward(t_settings *st)
{
	reset_image(st);
	set_pixels(st);
	st->player.pos_y += st->player.dir_y * 0.05;
	st->player.pos_x += st->player.dir_x * 0.05;
	printf("forward pos_y - %f dir_y - %f\n", st->player.pos_y, st->player.dir_y);
	printf("forward pos_x - %f dir_x - %f\n", st->player.pos_x, st->player.dir_x);
	printf("----\n");
	castray(st);
	draw_pixel((int)st->player.pos_y, (int)st->player.pos_x, st, 0xFF0000);
	mlx_put_image_to_window(st->mlx, st->mlx_win, st->img, 0, 0);
}

void	rotate(t_settings *st, float radius)
{
	double	new_dx;
	double	new_dy;
	double	theta;

	reset_image(st);
	set_pixels(st);
	theta = degrees_to_radians(radius);
	new_dx = st->player.dir_x * cos(theta) - st->player.dir_y * sin(theta);
	new_dy = st->player.dir_x * sin(theta) + st->player.dir_y * cos(theta);
	printf("new_dx %f\n", st->player.dir_y);
	printf("new_dy %f\n", st->player.dir_x);
	st->player.dir_x = new_dx;
	st->player.dir_y = new_dy;
	castray(st);
	draw_pixel((int)st->player.pos_y, (int)st->player.pos_x, st, 0xFF0000);
	mlx_put_image_to_window(st->mlx, st->mlx_win, st->img, 0, 0);
}

int	key_hook(int keycode, t_settings *settings)
{
	if (keycode == KEY_ESC)
		exit_game(settings);
	else if (keycode == KEY_UP)
		forward(settings);
	else if (keycode == KEY_DOWN)
		backward(settings);
	else if (keycode == KEY_LEFT)
		rotate(settings, 5.0);
	else if (keycode == KEY_RIGHT)
		rotate(settings, -5.0);
	return (0);
}
