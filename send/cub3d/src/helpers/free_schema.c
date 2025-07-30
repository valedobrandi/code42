/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_schema.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajolivie <ajolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:48:33 by ajolivie          #+#    #+#             */
/*   Updated: 2025/07/28 10:49:47 by ajolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	free_scheme(t_map *schema)
{
	int	i;

	i = 0;
	if (!schema)
		return ;
	while (i < schema->height)
	{
		free(schema->map[i].path);
		i++;
	}
	free(schema->map);
	free(schema);
	schema = NULL;
}
