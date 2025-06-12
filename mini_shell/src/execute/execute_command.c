/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:43:39 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/12 11:45:57 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void	call_execv(t_command *cmd, t_list **envp)
{
	pid_t	pid;
	char	*bin_path;
	char	**envp_list;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return ;
	}
	envp_list = linkedList_to_arr(*envp);
	if (!envp_list)
		return ;
	if (pid == 0)
	{
		if (apply_redirections(cmd->redirs, fd) < 0)
			exit(1);
		bin_path = get_path(cmd->cmd, envp_list);
		if (!bin_path)
		{
			ft_putstr_fd("Command not found\n", 2);
			exit(127);
		}
		if (!cmd->args || !cmd->args[0])
		{
			ft_putstr_fd("Invalid arguments\n", 2);
			if (bin_path != cmd->cmd)
				free(bin_path);
			exit(1);
		}
		execve(bin_path, cmd->args, envp_list);
		perror("execve failed");
		free(bin_path);
		exit(126);
	}
	else
		waitpid(pid, NULL, 0);
	free_array(envp_list);
}

int	execute_command(t_pipeline *pipeline, t_list **env_list)
{
	t_command	*cmd;
	pid_t pid = fork();
	int pipe_fd[2];
	int prev_fd;
	int			i;

	i = 0;
	prev_fd = -1;
	while (i < pipeline->cmd_count)
	{
		cmd = &pipeline->cmd[i];
		if (i < pipeline->cmd_count - 1)
			if (pipe(pipe_fd) < 0)
				return (perror("pipe"), 1);
		if (pid == 0)
		{
			if (prev_fd != -1)
			{
				dup2(prev_fd, STDIN_FILENO);
				close(prev_fd);
			}
			if (i < pipeline->cmd_count - 1)
			{
				dup2(pipe_fd[1], STDOUT_FILENO);
				close(pipe_fd[0]);
				close(pipe_fd[1]);
			}
			call_execv(cmd, env_list);
			exit(1);
			if (prev_fd != -1)
				close(prev_fd);
			if (i < pipeline->cmd - 1)
			{
				close(pipe_fd[1]);
				prev_fd = pipe_fd[0];
			}
			i++;
		}
		for (int j = 0; j < pipeline->cmd_count; j++)
			wait(NULL);
	}
	return (0);
}
