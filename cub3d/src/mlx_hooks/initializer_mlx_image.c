/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer_mlx_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:15:15 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/25 12:15:38 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>
#include <unistd.h>
#include "libft.h"
#include <stdlib.h>

static t_image_addr	*initialize(t_settings *st, t_image_addr *addr, char *path)
{
	void	*asset;

	asset = mlx_xpm_file_to_image(st->mlx, path, &addr->width, &addr->height);
	if (asset == NULL)
        exit_game(st);
	track_alloc(&st->mem_stack, asset);
	addr->data = mlx_get_data_addr(asset, &addr->bpp, &addr->line_len, &addr->endian);
	if (addr == NULL)
        exit_game(st);
}

void	initializer_mlx_image(t_settings *st)
{
	t_entries *content;
	t_list *tmp;

	tmp = st->rgb_texture;
    while (tmp)
    {
        content = tmp->content;
        if (content->type && content->path)
        {
            if (!ft_strcmp(content->type, "NO"))
				initialize(st, &st->mlx_texture.north, content->path);
			if (!ft_strcmp(content->type, "SO"))
				initialize(st, &st->mlx_texture.south, content->path);
			if (!ft_strcmp(content->type, "WE"))
				initialize(st, &st->mlx_texture.west, content->path);
			if (!ft_strcmp(content->type, "EA"))
				initialize(st, &st->mlx_texture.east, content->path);
        }
        tmp = tmp->next;
    }
    return ;
}
