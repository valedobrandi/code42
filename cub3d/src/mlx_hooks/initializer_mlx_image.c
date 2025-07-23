/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer_mlx_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:15:15 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/23 15:17:06 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>
#include <unistd.h>
#include "libft.h"

static void	*initialize(t_settings *st, char *path)
{
	void	*asset;
	void	*addr;
	int width;
	int height;

	printf("Error\nFailed to get image data for texture:  %s\n", path);
	asset = mlx_xpm_file_to_image(st->mlx, path, &width, &height);
	if (asset == NULL)
		return (exit_game(st), NULL);
	track_alloc(&st->mem_stack, asset);
	addr = mlx_get_data_addr(asset, &st->addr.bpp, &st->addr.line_len, &st->addr.endian);
	if (addr == NULL)
		return (exit_game(st), NULL);
	return (addr);
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
				st->mlx_texture.north_wall = initialize(st, content->path);
			if (!ft_strcmp(content->type, "SO"))
				st->mlx_texture.south_wall = initialize(st, content->path);
			if (!ft_strcmp(content->type, "WE"))
				st->mlx_texture.west_wall = initialize(st, content->path);
			if (!ft_strcmp(content->type, "EA"))
				st->mlx_texture.east_wall = initialize(st, content->path);
        }
        tmp = tmp->next;
    }
    return ;
}
