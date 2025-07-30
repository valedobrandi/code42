/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_raytrace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajolivie <ajolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:50:00 by yourname          #+#    #+#             */
/*   Updated: 2025/07/28 11:35:28 by ajolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <math.h>
#include <mlx.h>

void	load_texture_addr(int dir, t_image_addr *addr, t_settings **st)
{
	if (dir == 0)
		*addr = (*st)->mlx_texture.north;
	if (dir == 1)
		*addr = (*st)->mlx_texture.south;
	if (dir == 2)
		*addr = (*st)->mlx_texture.east;
	if (dir == 3)
		*addr = (*st)->mlx_texture.west;
}

void	wall_start_end(t_raycast *cast, double dist, int i, t_settings **st)
{
	double	ray_offset;
	double	corrected_distance;
	double	wall_height;

	ray_offset = cast->ray_angle - (*st)->player.pa;
	corrected_distance = dist * cos(ray_offset);
	if (corrected_distance < 0.5)
		corrected_distance = 0.5;
	cast->wall_distance = corrected_distance;
	wall_height = HEIGHT / cast->wall_distance;
	cast->wall_start = (HEIGHT / 2) - (wall_height / 2);
	cast->wall_end = (HEIGHT / 2) + (wall_height / 2);
	if (cast->wall_start < 0)
		cast->wall_start = 0;
	if (cast->wall_end >= HEIGHT)
		cast->wall_end = HEIGHT - 1;
}

void	load_texture(t_raycast *cast, t_dda_result ray, t_image_addr addr)
{
	cast->tex_x = (int)(ray.wall_x * addr.width);
	cast->tex_step = (double)addr.height
		/ (double)(cast->wall_end - cast->wall_start + 1);
	cast->tex_pos = 0.0;
}

static unsigned int	get_pixel_color(t_raycast *cast,
					t_image_addr *addr, t_settings **st, int y)
{
	int		tex_y;
	int		offset;

	if (y < cast->wall_start)
		return (((*st)->rbg_c[0] << 16)
			| ((*st)->rbg_c[1] << 8) | (*st)->rbg_c[2]);
	else if (y >= cast->wall_start && y <= cast->wall_end)
	{
		tex_y = (int)cast->tex_pos;
		if (tex_y < 0)
			tex_y += addr->height;
		cast->tex_pos += cast->tex_step;
		offset = tex_y * addr->line_len
			+ cast->tex_x * (addr->bpp / 8);
		return (*(unsigned int *)(addr->data + offset));
	}
	else
		return (((*st)->rbg_f[0] << 16)
			| ((*st)->rbg_f[1] << 8) | (*st)->rbg_f[2]);
}

void	render(t_raycast *cast, t_image_addr addr, t_settings **st, int i)
{
	int				y;
	int				offset;
	unsigned int	color;

	y = 0;
	while (y < HEIGHT)
	{
		color = get_pixel_color(cast, &addr, st, y);
		offset = y * (*st)->addr.line_len + i * ((*st)->addr.bpp / 8);
		*(unsigned int *)((*st)->img_data + offset) = color;
		y++;
	}
}
