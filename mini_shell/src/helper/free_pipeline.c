/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 08:16:27 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/20 09:46:49 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

static void	free_args(t_command *cmd)
{
	int	i;

	i = 0;
	if (!cmd->args)
		return ;
	while (cmd->args[i])
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
		free(cmd->redirs[i]);
		i++;
	}
}

void	free_pipeline(t_pipeline *pipeline)
{
	int	i;

	if (!pipeline)
		return ;
	i = 0;
	while (i < pipeline->cmd_count)
	{
		free(pipeline->cmds[i].cmd);
		free_args(&pipeline->cmds[i]);
		free(pipeline->cmds[i].args);
		free_redirs(&pipeline->cmds[i]);
		i++;
	}
	free(pipeline->cmds);
	free(pipeline);
}
