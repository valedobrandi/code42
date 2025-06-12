/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:45:41 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/03 13:26:17 by bde-albu         ###   ########.fr       */
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
