/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:02:08 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/18 12:11:45 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

static int	restore_std(int saved_stdin, int saved_stdout)
{
	dup2(saved_stdin, STDIN_FILENO);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdin);
	close(saved_stdout);
	return (0);
}

static int	execute_builtin_cmd(t_pipeline *pipeline, t_list **envp_list,
		int *exit_code)
{
	t_command	cmd;

	cmd = pipeline->cmds[0];
	if (ft_strcmp("exit", cmd.cmd) == 0)
	{
		*exit_code = builtin_exit(cmd.args, 0);
		return (1);
	}
	else
		*exit_code = exec_builtin(cmd.cmd, cmd.args, envp_list);
	return (0);
}

int	builtins_cmd(t_pipeline *pipeline, t_list **envp_list, int *exit_code)
{
	int	saved_stdin;
	int	saved_stdout;

	saved_stdin = dup(STDIN_FILENO);
	saved_stdout = dup(STDOUT_FILENO);
	if (saved_stdin < 0 || saved_stdin < 0)
		return (perror("dup"), 0);
	if (apply_redirections(pipeline->cmds[0].redirs))
	{
		*exit_code = 1;
		return (restore_std(saved_stdin, saved_stdout));
	}
	if (execute_builtin_cmd(pipeline, envp_list, exit_code))
		return (1);
	restore_std(saved_stdin, saved_stdout);
	return (0);
}
