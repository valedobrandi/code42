/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer_mlx_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:15:15 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/22 14:48:29 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>
#include <unistd.h>
#include "libft.h"

void	*initialize(t_settings *st, char *path)
{
	void	*asset;

	asset = mlx_xpm_file_to_image(st->mlx, path, st->texture_width,
			st->texture_heigth);
	if (asset == NULL)
		return (exit_game(st), NULL);
	track_alloc(&st->mem_stack, asset);
	return (asset);
}

void	initializer_mlx_image(t_settings *st)
{
	t_entries *content;

	ft_memset(&st->mlx_texture, 0, sizeof(t_texture));
    while (st->rgb_texture)
    {
        content = st->rgb_texture->content;
        if (content->type && content->path)
        {
            if (!ft_strcmp(content->type, "NO"))
				st->mlx_texture.north_wall = initialize(st, content->path);
			if (!ft_strcmp(content->type, "SO"))
				st->mlx_texture.south_wall = initialize(st, content->path);
			if (!ft_strcmp(content->type, "WE"))
				st->mlx_texture.west_wall = initialize(st, content->path);
			if (!ft_strcmp(content->type, "EA"))
				st->mlx_texture.east_wall = initialize(st, content->path);
        }
        st->rgb_texture = st->rgb_texture->next;
    }
    return ;
}
