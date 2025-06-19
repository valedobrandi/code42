/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:45:53 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/18 15:50:10 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int	is_builtin(char *cmd)
{
	return (!ft_strcmp("cd", cmd) || !ft_strcmp("echo", cmd)
		|| !ft_strcmp("env", cmd) || !ft_strcmp("export", cmd)
		|| !ft_strcmp("pwd", cmd) || !ft_strcmp("unset", cmd)
		|| !ft_strcmp("exit", cmd));
}

int	exec_builtin(char *cmd, char **args, t_list **env_list)
{
	if (ft_strcmp("cd", cmd) == 0)
		return (builtin_cd(args));
	else if (ft_strcmp("echo", cmd) == 0)
		return (builtin_echo(args));
	else if (ft_strcmp("env", cmd) == 0)
		return (builtin_env(args, env_list));
	else if (ft_strcmp("export", cmd) == 0)
		return (builtin_export(args, env_list));
	else if (ft_strcmp("pwd", cmd) == 0)
		return (builtin_pwd());
	else if (ft_strcmp("unset", cmd) == 0)
		return (builtin_unset(args, env_list));
	else if (ft_strcmp("exit", cmd) == 0)
		return (1);
	return (0);
}
