/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:52:10 by ajolivie          #+#    #+#             */
/*   Updated: 2025/06/18 15:39:25 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdio.h>
#include <unistd.h>

static void	parent_process(t_exec_pipe *t, t_pipeline *pipeline)
{
	{
		if (t->prev_fd != -1)
			close(t->prev_fd);
		if (t->i < pipeline->cmd_count - 1)
		{
			close(t->pipe_fd[1]);
			t->prev_fd = t->pipe_fd[0];
		}
		if (t->i == pipeline->cmd_count - 1)
			t->last_pid = t->pid;
	}
}

static int	prepare_command(t_exec_pipe *t, t_pipeline *pipeline,
		int *exit_code)
{
	expand_system_return(*exit_code, pipeline->cmds[t->i].args, &pipeline->cmds[t->i].cmd);
	if (t->i < pipeline->cmd_count - 1)
	{
		if (pipe(t->pipe_fd) < 0)
			return (perror("pipe"), 1);
	}
	return (0);
}

static void	init_exec_pipe(t_exec_pipe *t)
{
	t->i = 0;
	t->prev_fd = -1;
	t->last_pid = -1;
}

int	exec_pipeline(t_pipeline *pipeline, t_list **envp_list, int *exit_code,
		char **env)
{
	t_exec_pipe	t;

	init_exec_pipe(&t);
	while (t.i < pipeline->cmd_count)
	{
		if (!pipeline->cmds[t.i].cmd)
		{
			t.i++;
			continue ;
		}
		if (prepare_command(&t, pipeline, exit_code) != 0)
			return (free_array(env), 0);
		t.pid = fork();
		if (t.pid < 0)
			return (perror("fork"), free_array(env), 0);
		if (t.pid == 0)
			child_pipeline_process(pipeline, &t, envp_list, env);
		else
			parent_process(&t, pipeline);
		t.i++;
	}
	wait_children_process_exit(t.last_pid, exit_code);
	return (free_array(env), 0);
}
