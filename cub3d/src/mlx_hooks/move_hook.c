#include "cub3d.h"
#include <math.h>
#include <mlx.h>
#include <stdio.h>

void backward(t_settings *st)
{
    double next_py;
    double next_px;
    double margin;
    
    next_py = st->player.py + st->player.pdy;
    next_px = st->player.px + st->player.pdx;
    margin = 0.5;
    if (st->scheme->map[(int)(st->player.py)].path[(int)(next_px + margin * ((st->player.pdx > 0) ? 1 : -1))] != '1')
        st->player.px = next_px;
    if (st->scheme->map[(int)(next_py + margin * ((st->player.pdy > 0) ? 1 : -1))].path[(int)(st->player.px)] != '1')
        st->player.py = next_py;
    raytracer_render(&st);
    mlx_put_image_to_window(st->mlx, st->mlx_win, st->img, 0, 0);
}

void forward(t_settings *st)
{
    double next_py;
    double next_px;
    double margin;

    next_py = st->player.py + st->player.pdy;
    next_px = st->player.px + st->player.pdx;
    margin = 0.5;
    if (st->scheme->map[(int)(st->player.py)].path[(int)(next_px + margin * ((st->player.pdx > 0) ? 1 : -1))] != '1')
        st->player.px = next_px;
    if (st->scheme->map[(int)(next_py + margin * ((st->player.pdy > 0) ? 1 : -1))].path[(int)(st->player.px)] != '1')
        st->player.py = next_py;
    raytracer_render(&st);
    mlx_put_image_to_window(st->mlx, st->mlx_win, st->img, 0, 0);
}

void rotate_rigth(t_settings *st)
{
    st->player.pa -= ROTATE_SPEED;
    if (st->player.pa < 0)
        st->player.pa += 2 * PI;
    st->player.pdx = cos(st->player.pa) * MOVE_SPEED;
    st->player.pdy = sin(st->player.pa) * MOVE_SPEED;
    raytracer_render(&st);
    mlx_put_image_to_window(st->mlx, st->mlx_win, st->img, 0, 0);
}

void rotate_left(t_settings *st)
{
    st->player.pa += ROTATE_SPEED;
    if (st->player.pa > 2 * PI)
        st->player.pa -= 2 * PI;
    st->player.pdx = cos(st->player.pa) * MOVE_SPEED;
    st->player.pdy = sin(st->player.pa) * MOVE_SPEED;
    raytracer_render(&st);
    mlx_put_image_to_window(st->mlx, st->mlx_win, st->img, 0, 0);
}