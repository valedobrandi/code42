/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajolivie <ajolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:45:41 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/18 11:35:31 by ajolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../include/minishell.h"

void	free_token_list(t_token_list *token_list)
{
	int	i;

	i = 0;
	if (!token_list)
		return ;
	while (i < token_list->size)
	{
		free(token_list->tokens[i].value);
		i++;
	}
	free(token_list->tokens);
	free(token_list);
}
