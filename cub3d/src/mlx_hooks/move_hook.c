#include "cub3d.h"
#include <math.h>
#include <mlx.h>
#include <stdio.h>

void	backward(t_settings *st)
{
	/* reset_image(st);
	set_pixels(st); */
	st->player.py -= st->player.pdy;
	st->player.px -= st->player.pdx;
	printf("backward pos_y - %f dir_y - %f\n", st->player.py, st->player.pdy);
	printf("backward pos_x - %f dir_x - %f\n", st->player.px, st->player.pdx);
	printf("----\n");
	//drawrays3d(st);
	//draw_pixel((int)st->player.py, (int)st->player.px, st, 0xFF0000);
    render3d(&st);
	mlx_put_image_to_window(st->mlx, st->mlx_win, st->img, 0, 0);
}

void	forward(t_settings *st)
{
	/* reset_image(st);
	set_pixels(st); */
	st->player.py += st->player.pdy;
	st->player.px += st->player.pdx;
	printf("forward pos_y - %f dir_y - %f\n", st->player.py, st->player.pdy);
	printf("forward pos_x - %f dir_x - %f\n", st->player.px, st->player.pdx);
	printf("----\n");
	//drawrays3d(st);
	//draw_pixel((int)st->player.py, (int)st->player.px, st, 0xFF0000);
    render3d(&st);
	mlx_put_image_to_window(st->mlx, st->mlx_win, st->img, 0, 0);
}

void	rotate_rigth(t_settings *st)
{
	/* reset_image(st);
	set_pixels(st); */
    st->player.pa -= ROTATE_SPEED;
    if (st->player.pa < 0)  st->player.pa += 2*PI;
	/* theta = degrees_to_radians(radius);
	new_dx = st->player.pdx * cos(theta) - st->player.pdy * sin(theta);
	new_dy = st->player.pdx * sin(theta) + st->player.pdy * cos(theta); */
	st->player.pdx = cos(st->player.pa) * MOVE_SPEED;
	st->player.pdy = sin(st->player.pa) * MOVE_SPEED;
	printf("new_dx %f\n", st->player.pdy);
	printf("new_dy %f\n", st->player.pdx);
	//drawrays3d(st);
	//draw_pixel((int)st->player.py, (int)st->player.px, st, 0xFF0000);
    render3d(&st);
	mlx_put_image_to_window(st->mlx, st->mlx_win, st->img, 0, 0);
}

void	rotate_left(t_settings *st)
{

	/* reset_image(st);
	set_pixels(st); */
    st->player.pa += ROTATE_SPEED;
    if (st->player.pa > 2*PI) st->player.pa -= 2*PI;
    
	/* theta = degrees_to_radians(radius);
	new_dx = st->player.pdx * cos(theta) - st->player.pdy * sin(theta);
	new_dy = st->player.pdx * sin(theta) + st->player.pdy * cos(theta); */
	st->player.pdx = cos(st->player.pa) * MOVE_SPEED;
	st->player.pdy = sin(st->player.pa) * MOVE_SPEED;
	printf("new_dx %f\n", st->player.pdy);
	printf("new_dy %f\n", st->player.pdx);
	/* drawrays3d(st);
	draw_pixel((int)st->player.py, (int)st->player.px, st, 0xFF0000); */
    render3d(&st);
	mlx_put_image_to_window(st->mlx, st->mlx_win, st->img, 0, 0);
}