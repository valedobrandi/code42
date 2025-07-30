/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:15:18 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/29 10:27:42 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <mlx.h>

int	mouse_move(int x, int y, t_settings *st)
{
	int	center_x;
	int	delta_x;

	(void)y;
	center_x = WIDTH / 2;
	delta_x = x - center_x;
	if (delta_x == 0)
		return (0);
	st->player.pa += delta_x * 0.001;
	if (st->player.pa < 0)
		st->player.pa += 2 * PI;
	if (st->player.pa >= 2 * PI)
		st->player.pa -= 2 * PI;
	st->player.pdx = cos(st->player.pa);
	st->player.pdy = sin(st->player.pa);
	mlx_mouse_move(st->mlx, st->mlx_win, WIDTH / 2, HEIGHT / 2);
	return (0);
}

int	set_mlx_hooks(t_settings *st)
{
	mlx_hook(st->mlx_win, 2, 1L << 0, key_press, st);
	mlx_hook(st->mlx_win, 3, 1L << 1, key_release, st);
	mlx_loop_hook(st->mlx, key_update, st);
	mlx_hook(st->mlx_win, 6, 1L << 6, mouse_move, st);
	mlx_hook(st->mlx_win, 17, 0, exit_game, st);
	return (0);
}
