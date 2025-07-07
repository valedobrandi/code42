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
#include "libft.h"

/* void	reset_image(t_settings *st)
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
} */





int	key_press(int keycode, t_settings *st)
{
	if (keycode == KEY_ESC)
		exit_game(st);
	else if (keycode == KEY_UP)
		st->keys.up = 1;
	else if (keycode == KEY_DOWN)
		st->keys.down = 1;
	else if (keycode == KEY_LEFT)
		st->keys.rigth = 1;
	else if (keycode == KEY_RIGHT)
        st->keys.left = 1;
	return (0);
}
int	key_release(int keycode, t_settings *st)
{
	if (keycode == KEY_ESC)
		exit_game(st);
	else if (keycode == KEY_UP)
		st->keys.up = 0;
	else if (keycode == KEY_DOWN)
		st->keys.down = 0;
	else if (keycode == KEY_LEFT)
		st->keys.rigth = 0;
	else if (keycode == KEY_RIGHT)
        st->keys.left = 0;
	return (0);
}

int key_update(t_settings *st)
{
	if (st->keys.up)
		forward(st);
	if (st->keys.down)
		backward(st);
    if (st->keys.rigth)
		rotate_rigth(st);
    if (st->keys.left)
		rotate_left(st);
	return (0);
}


