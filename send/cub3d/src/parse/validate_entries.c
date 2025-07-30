/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_entries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:12:50 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/28 11:38:52 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static int	validate_type(const char *type)
{
	return (!ft_strcmp(type, "F") || !ft_strcmp(type, "C") || !ft_strcmp(type,
			"NO") || !ft_strcmp(type, "EA") || !ft_strcmp(type, "SO")
		|| !ft_strcmp(type, "WE"));
}

static int	validate_entries(t_list *lst)
{
	t_entries	*content;

	if (!lst)
		return (1);
	while (lst)
	{
		content = lst->content;
		if (content->type && content->path)
		{
			if (validate_type(content->type))
				return (1);
		}
		else
			return (1);
		lst = lst->next;
	}
	return (0);
}
