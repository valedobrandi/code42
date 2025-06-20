/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_pipeline_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:27:38 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/20 14:33:11 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static char	*resolve_bin_path_pipeline(t_pipeline *pipeline, int index,
		char **env)
{
	char	*bin_path;

	if (is_path(pipeline->cmds[index].cmd))
		return (pipeline->cmds[index].cmd);
	bin_path = get_path(pipeline->cmds[index].cmd, env);
	if (!bin_path || !pipeline->cmds[index].args
		|| !pipeline->cmds[index].args[0])
	{
		ft_putstr_fd(pipeline->cmds[index].cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
		if (bin_path && bin_path != pipeline->cmds[index].cmd)
			free(bin_path);
		return (NULL);
	}
	validate_path(pipeline->cmds[index].cmd, bin_path, env);
	return (bin_path);
}

static void	exit_with_error(char **env, char *bin_path, int code)
{
	if (bin_path)
		free(bin_path);
	free_array(env);
	exit(code);
}

static void	validate_dup(int count_cmd, t_exec_pipe *t)
{
	if (t->prev_fd != -1)
	{
		dup2(t->prev_fd, STDIN_FILENO);
		close(t->prev_fd);
	}
	if (t->i < count_cmd - 1)
	{
		close(t->pipe_fd[0]);
		dup2(t->pipe_fd[1], STDOUT_FILENO);
		close(t->pipe_fd[1]);
	}
}

void	child_pipeline_process(t_pipeline *pipeline, t_exec_pipe *t,
		t_list **envp_list, char **env)
{
	char	*bin_path;
	int		ret;

	bin_path = NULL;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	validate_dup(pipeline->cmd_count, t);
	execute_redirects(pipeline->cmds[t->i], env);
	if (is_builtin(pipeline->cmds[t->i].cmd))
	{
		ret = exec_builtin(pipeline->cmds[t->i].cmd, pipeline->cmds[t->i].args,
				envp_list);
		free_array(env);
		exit(ret);
	}
	else
	{
		if (pipeline->cmds[0].cmd[0] == '\0')
			exit_cleanup(env, NULL, 0);
		bin_path = resolve_bin_path_pipeline(pipeline, t->i, env);
		if (!bin_path)
			exit_with_error(env, NULL, 127);
		execute_execve(pipeline->cmds[t->i].args, pipeline->cmds[0].cmd,
			bin_path, env);
	}
}
