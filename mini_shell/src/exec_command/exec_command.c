/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:56:45 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/19 11:36:24 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void	exit_cleanup(char **env, char *bin_path, int code)
{
	if (bin_path && bin_path != NULL && bin_path != env[0])
		free(bin_path);
	free_array(env);
	exit(code);
}

static char	*resolve_bin_path(char *cmd, char **env)
{
	char	*path;

	if (is_path(cmd))
		return (cmd);
	path = get_path(cmd, env);
	if (!path)
	{
		ft_putstr_fd("path: command not found\n", 2);
		free_array(env);
		exit(127);
	}
	validate_path(cmd, path, env);
	return (path);
}

static void	child_process(t_pipeline *pipeline, char **env)
{
	char	*bin_path;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	if (apply_redirections(pipeline->cmds[0].redirs))
		exit_cleanup(env, NULL, 1);
	execute_redirects(pipeline->cmds[0], env);
	if (pipeline->cmds[0].cmd[0] == '\0')
		exit_cleanup(env, NULL, 0);
	bin_path = resolve_bin_path(pipeline->cmds[0].cmd, env);
	if (!pipeline->cmds[0].args || !pipeline->cmds[0].args[0])
	{
		ft_putstr_fd("not a valid identifier\n", 2);
		exit_cleanup(env, bin_path, 1);
	}
	execute_execve(pipeline->cmds[0].args, pipeline->cmds[0].cmd, bin_path,
		env);
}

static int	handle_builtin(t_pipeline *pipeline, t_list **envp_list,
		int *exit_code)
{
	if (builtins_cmd(pipeline, envp_list, exit_code))
		return (1);
	return (0);
}

int	exec_command(t_pipeline *pipeline, t_list **envp_list, int *exit_code,
		char **env)
{
	pid_t	pid;

	expand_system_return(*exit_code, pipeline->cmds[0].args);
	if (is_builtin(pipeline->cmds[0].cmd))
		return (free_array(env), handle_builtin(pipeline, envp_list, exit_code));
	pid = fork();
	if (pid < 0)
		return (free_array(env), perror("fork"), 1);
	if (pid == 0)
		child_process(pipeline, env);
	wait_children_process_exit(pid, exit_code);
	free_array(env);
	return (0);
}
