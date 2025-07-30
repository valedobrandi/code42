/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:14:19 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/28 11:50:11 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

static int	open_texture(char *type, char *path)
{
	int	fd;

	if (!ft_strcmp(type, "NO") || !ft_strcmp(type, "SO") || !ft_strcmp(type,
			"WE") || !ft_strcmp(type, "EA"))
	{
		fd = open(path, O_RDONLY);
		if (fd == -1)
			return (1);
		close(fd);
	}
	return (0);
}

int	validate_texture(t_list *lst)
{
	t_entries	*content;

	if (!lst)
		return (1);
	while (lst)
	{
		content = lst->content;
		if (content->type && content->path)
		{
			if (open_texture(content->type, content->path))
				return (1);
		}
		else
			return (1);
		lst = lst->next;
	}
	return (0);
}
