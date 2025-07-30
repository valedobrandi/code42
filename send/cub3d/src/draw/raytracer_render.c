/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:12:31 by ajolivie          #+#    #+#             */
/*   Updated: 2025/07/28 11:54:57 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <math.h>
#include <mlx.h>

void	raytracer_render(t_settings **st)
{
	t_render	r;

	r.i = 0;
	while (r.i < WIDTH)
	{
		r.pixel_ratio = (double)r.i / (double)WIDTH;
		r.centered_ratio = r.pixel_ratio - 0.5;
		r.angle_offset = r.centered_ratio * (60.0 * (PI / 180.0));
		r.cast.ray_angle = (*st)->player.pa + r.angle_offset;
		r.ray = cast_dda_ray(*st, r.cast.ray_angle);
		load_texture_addr(r.ray.wall_direction, &r.addr, st);
		wall_start_end(&r.cast, r.ray.raw_distance, r.i, st);
		load_texture(&r.cast, r.ray, r.addr);
		render(&r.cast, r.addr, st, r.i);
		r.i++;
	}
}
