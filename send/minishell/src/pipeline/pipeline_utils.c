/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajolivie <ajolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:46:48 by ajolivie          #+#    #+#             */
/*   Updated: 2025/06/18 10:59:19 by ajolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include "libft.h"

int	count_pipe(t_token_list *token_list)
{
	int	count;
	int	index;

	index = 0;
	count = 0;
	while (index < token_list->size)
	{
		if (token_list->tokens[index].type == TOKEN_PIPE)
			count++;
		index++;
	}
	return (count);
}

t_pipeline	*init_pipeline(void)
{
	t_pipeline	*pipeline;

	pipeline = malloc(sizeof(t_pipeline));
	if (pipeline == NULL)
		return (NULL);
	ft_memset(pipeline, 0, sizeof(t_pipeline));
	return (pipeline);
}

int	init_commands(t_pipeline *pipeline, int size)
{
	int	i;

	pipeline->cmds = malloc(sizeof(t_command) * size);
	if (pipeline->cmds == NULL)
		return (1);
	i = 0;
	while (i < size)
	{
		ft_memset(&pipeline->cmds[i], 0, sizeof(t_command));
		i++;
	}
	pipeline->cmd_count = size;
	return (0);
}

t_redir_type	get_type(t_token_type token)
{
	if (token == TOKEN_REDIRECT_IN)
		return (REDIR_IN);
	else if (token == TOKEN_REDIRECT_OUT)
		return (REDIR_OUT);
	else if (token == TOKEN_REDIRECT_APPEND)
		return (REDIR_APPEND);
	else
		return (REDIR_HEREDOC);
}
