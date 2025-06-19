/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:43:39 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/19 11:29:57 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int	execute_command(t_pipeline *pipeline, t_list **env_list, int *exit_code)
{
	char	**env;

	env = linkedlist_to_arr(*env_list);
	if (!env)
		return (ft_putendl_fd("env MEM fail.", 2), 0);
	g_sigint_received = 1;
	if (pipeline->cmd_count > 1)
		return (exec_pipeline(pipeline, env_list, exit_code,
				env));
	if (pipeline->cmds[0].cmd)
		return (exec_command(pipeline, env_list, exit_code,
				env));
	if (!pipeline->cmds[0].cmd)
		*exit_code = 0;
	free_array(env);
	return (0);
}
