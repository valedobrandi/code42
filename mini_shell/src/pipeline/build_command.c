/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:12:49 by ajolivie          #+#    #+#             */
/*   Updated: 2025/06/20 09:39:47 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

static int	handle_redirection(t_command *cmd, t_token *token, int *index,
		int *redir_count)
{
	cmd->redirs[*redir_count] = malloc(sizeof(t_redir));
	if (!cmd->redirs[*redir_count])
		return (1);
	cmd->redirs[*redir_count]->file = ft_strdup(token[*index + 1].value);
	if (!cmd->redirs[*redir_count]->file)
		return (1);
	cmd->redirs[*redir_count]->type = get_type(token[*index].type);
	(*index)++;
	(*redir_count)++;
	return (0);
}

static int	handle_word(t_command *cmd, t_token *token, int *index, int *argc)
{
	if (!cmd->cmd && ft_strcmp(token[*index].value, ""))
	{
		cmd->cmd = ft_strdup(token[*index].value);
		if (!cmd->cmd)
			return (ft_putendl_fd("cmd->cmd MEM fail.", 2), 1);
	}
	if (ft_strcmp(token[*index].value, ""))
	{
		cmd->args[*argc] = ft_strdup(token[*index].value);
		if (!cmd->args[*argc])
			return (ft_putendl_fd("cmd->args[argc] MEM fail.", 2), 1);
		(*argc)++;
	}
	return (0);
}

static int	process_tokens(t_command *cmd, t_token *token, int token_size,
		int *index)
{
	int	argc;
	int	redir_count;

	argc = 0;
	redir_count = 0;
	while (*index < token_size && token[*index].type != TOKEN_PIPE)
	{
		if (is_redirection(token[*index].type))
		{
			if (handle_redirection(cmd, token, index, &redir_count))
				return (1);
		}
		else if (token[*index].type == TOKEN_WORD)
		{
			if (handle_word(cmd, token, index, &argc))
				return (1);
		}
		(*index)++;
	}
	cmd->args[argc] = NULL;
	cmd->redirs[redir_count] = NULL;
	if (*index < token_size && token[*index].type == TOKEN_PIPE)
		(*index)++;
	return (0);
}

int	build_commmand(t_token_list *token_list, t_command *cmd, int token_size,
		int *index)
{
	cmd->args = malloc(sizeof(char *) * (token_list->size + 1));
	if (cmd->args == NULL)
		return (1);
	if (process_tokens(cmd, token_list->tokens, token_size, index))
		return (1);
	return (0);
}
