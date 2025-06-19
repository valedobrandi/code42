/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 08:16:27 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/19 10:04:47 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

static void	free_args(t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd->args && cmd->args[i])
	{
		free(cmd->args[i]);
		i++;
	}
}

static void	free_redirs(t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd->redirs[i])
	{
		free(cmd->redirs[i]->file);
		i++;
	}
}

void	free_pipeline(t_pipeline *pipeline)
{
	t_command	*cmd;
	int			i;

	if (!pipeline)
		return ;
	i = 0;
	while (i < pipeline->cmd_count)
	{
		cmd = &pipeline->cmds[i];
		free(cmd->cmd);
		free_args(cmd);
		free(cmd->args);
		free_redirs(cmd);
		free(cmd);
		i++;
	}
	free(pipeline);
}
