/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_scheme.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 08:29:46 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/04 08:58:33 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"

int	allocate_scheme(t_map **schema)
{
	*schema = malloc(sizeof(t_map));
	if (!*schema)
		return (1);
	(*schema)->map = malloc(sizeof(t_map_line) * BUFFER);
	if (!(*schema)->map)
		return (1);
	return (0);
}
