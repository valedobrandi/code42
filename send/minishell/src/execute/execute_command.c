/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajolivie <ajolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:43:39 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/20 11:16:07 by ajolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <unistd.h>

static int	handle_redirections_only(t_pipeline *pipeline, char **env,
		int *exit_code)
{
	int	saved_stdout;
	int	saved_stdin;

	saved_stdout = dup(STDOUT_FILENO);
	saved_stdin = dup(STDIN_FILENO);
	if (pipeline->cmds[0].redirs[0])
	{
		if (apply_redirections(pipeline->cmds[0].redirs) != 0)
		{
			*exit_code = 1;
			free_array(env);
			return (1);
		}
		dup2(saved_stdout, STDOUT_FILENO);
		dup2(saved_stdin, STDIN_FILENO);
		close(saved_stdout);
		close(saved_stdin);
	}
	*exit_code = 0;
	return (0);
}

int	execute_command(t_pipeline *pipeline, t_list **env_list, int *exit_code)
{
	char	**env;

	env = linkedlist_to_arr(*env_list);
	if (!env)
		return (ft_putendl_fd("env MEM fail.", 2), 0);
	g_sigint_received = 1;
	if (pipeline->cmd_count > 1)
		return (exec_pipeline(pipeline, env_list, exit_code, env));
	if (pipeline->cmds[0].cmd)
		return (exec_command(pipeline, env_list, exit_code, env));
	if (handle_redirections_only(pipeline, env, exit_code))
		return (0);
	free_array(env);
	return (0);
}
