/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hook_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajolivie <ajolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:05:15 by ajolivie          #+#    #+#             */
/*   Updated: 2025/07/28 11:15:33 by ajolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <math.h>
#include <mlx.h>

void	rotate_right(t_settings *st)
{
	st->player.pa -= ROTATE_SPEED;
	if (st->player.pa < 0)
		st->player.pa += 2 * PI;
	st->player.pdx = cos(st->player.pa) * MOVE_SPEED;
	st->player.pdy = sin(st->player.pa) * MOVE_SPEED;
}

void	rotate_left(t_settings *st)
{
	st->player.pa += ROTATE_SPEED;
	if (st->player.pa > 2 * PI)
		st->player.pa -= 2 * PI;
	st->player.pdx = cos(st->player.pa) * MOVE_SPEED;
	st->player.pdy = sin(st->player.pa) * MOVE_SPEED;
}
