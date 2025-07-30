/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_flood.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:11:08 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/03 15:11:39 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	ft_fill_flood(t_map *schema, int height, int width, char checker)
{
	char	curr;

	if (height < 0 || height >= schema->height)
	{
		if (checker == '0')
			return (1);
		return (0);
	}
	if (width < 0 || width >= schema->map[height].length)
	{
		if (checker == '0')
			return (1);
		return (0);
	}
	curr = schema->map[height].path[width];
	if (curr == 'F' || curr == '1')
		return (0);
	if (check_wall(checker, curr))
		return (1);
	schema->map[height].path[width] = 'F';
	if (flood(schema, height, width, curr))
		return (1);
	return (0);
}
