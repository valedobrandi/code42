/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:05:11 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/28 09:49:37 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>

void	draw_map(t_settings *st)
{
    raytracer_render(&st);
	draw_minimap(st);
	mlx_put_image_to_window(st->mlx, st->mlx_win, st->img, 0, 0);
}
