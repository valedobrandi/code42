/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:47:36 by ajolivie          #+#    #+#             */
/*   Updated: 2025/06/19 10:30:58 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include "libft.h"

t_pipeline	*build_pipeline(t_token_list *token_list)
{
	t_pipeline	*pipeline;
	int			command_count;
	int			cmd_index;
	int			index;

	pipeline = init_pipeline();
	if (!pipeline)
		return (NULL);
	command_count = count_pipe(token_list) + 1;
	if (init_commands(pipeline, command_count))
		return (NULL);
	index = 0;
	cmd_index = 0;
	while (index < token_list->size && cmd_index < command_count)
	{
		if (build_commmand(token_list, &pipeline->cmds[cmd_index],
				token_list->size, &index))
			return (NULL);
		cmd_index++;
	}
	return (pipeline);
}
