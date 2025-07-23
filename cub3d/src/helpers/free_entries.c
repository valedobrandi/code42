/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_entries.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:22:29 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/23 11:22:44 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"

void free_entries(void *content)
{
    t_entries *t;

    t = content;
    if (t->path)
        free(t->path);
    if (t->type)
        free(t->type);
    free(t);
}
