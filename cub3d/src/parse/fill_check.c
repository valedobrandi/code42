/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:14:27 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/04 15:21:42 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdio.h>

static int	check_wall(int prev, char next)
{
	return (prev == '0' && next != '1' && next != '0' && next != 'F');
}

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

static void	init(int *dest, const int *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

int	flood(t_map *schema, int y, int x, char curr)
{
	int	dx[8];
	int	dy[8];
	int	index;

	index = 0;
	init(dx, (int []){0, 0, 1, -1, 1, -1, 1, -1}, 8);
	init(dy, (int []){1, -1, 0, 0, 1, 1, -1, -1}, 8);
	while (index < 8)
	{
		if (ft_fill_flood(schema, y + dy[index], x + dx[index], curr))
			return (1);
		index++;
	}
	return (0);
}

int	fill_check(t_map *schema, t_player player)
{
	int	y;
	int	x;

	y = 0;
	schema->map[(int) player.py].path[(int) player.px] = '0';
	while (y < schema->height)
	{
		x = 0;
		while (x < schema->map[y].length)
		{
			if (schema->map[y].path[x] == '0')
				if (ft_fill_flood(schema, y, x, '0'))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}
