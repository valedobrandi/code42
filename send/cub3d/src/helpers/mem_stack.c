/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajolivie <ajolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:15:32 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/28 10:51:51 by ajolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <unistd.h>
#include <mlx.h>

void	*track_alloc(t_mem_stack *mem, void *ptr)
{
	if (mem->top < 18)
		mem->ptr[mem->top++] = ptr;
	return (ptr);
}

void	free_all(t_mem_stack *mem, void *mlx)
{
	int	i;

	i = 0;
	while (i < mem->top)
	{
		mlx_destroy_image(mlx, mem->ptr[i]);
		mem->ptr[i] = NULL;
		i++;
	}
}
