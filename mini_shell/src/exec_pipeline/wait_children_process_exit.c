/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children_process_exit.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:52:25 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/18 15:49:06 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/wait.h>
#include <signal.h>

void	wait_children_process_exit(pid_t last_pid, int *exit_code)
{
	int		status;
	int		sig;
	pid_t	pid;

	pid = waitpid(-1, &status, 0);
	while (pid > 0)
	{
		if (last_pid == pid)
		{
			if (WIFEXITED(status))
				*exit_code = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
			{
				sig = WTERMSIG(status);
				if (sig == SIGINT)
					*exit_code = 130;
				else
					*exit_code = 1;
			}
		}
		pid = waitpid(-1, &status, 0);
	}
}
