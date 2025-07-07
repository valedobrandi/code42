#include "cub3d.h"
#include <mlx.h>

int	set_mlx_hooks(t_settings *st)
{
	mlx_hook(st->mlx_win, 2, 1L<<0, key_press, st);
    mlx_hook(st->mlx_win, 3, 1L<<1, key_release, st);
    mlx_loop_hook(st->mlx, key_update, st);
	mlx_hook(st->mlx_win, 17, 0, exit_game, st);
	return (0);
}
