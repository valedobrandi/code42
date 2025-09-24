/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:13:22 by ajolivie          #+#    #+#             */
/*   Updated: 2025/06/23 08:42:42 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	update_path(char *key, char *pwd, t_list **env_list)
{
	t_init_env	*env;

	env = find_variable(*env_list, key);
	if (!env || !env->sing)
		return (1);
	if (env->value)
		free(env->value);
	if (env->value)
		env->value = ft_strdup(pwd);
	else
		env->value = ft_strdup("");
	return (0);
}

static int	home_path(t_list **env_list)
{
	t_init_env	*home;

	home = find_variable(*env_list, "HOME");
	if (!home || !home->value)
		return (ft_putendl_fd("cd: HOME not set", 2), 1);
	if (chdir(home->value) != 0)
		return (perror("cd"), 1);
	return (0);
}

static int	folder_path(char *arg, t_list **env_list)
{
	t_init_env	*path;
	char		*expand_var;

	path = find_variable(*env_list, "OLDPWD");
	if (!path || !path->value)
		return (ft_putendl_fd("cd: OLDPWD not set", 2), 1);
	if (!ft_strcmp(arg, "-"))
	{
		if (chdir(path->value) != 0)
			return (ft_putendl_fd("minishell: cd: OLDPWD not set", 2), 1);
		ft_putendl_fd(path->value, 1);
	}
	else if (arg[0] == '~')
	{
		expand_var = expand_env(arg + 1, env_list);
		if (!expand_var)
			return (perror("cd"), 1);
		if (chdir(expand_var) != 0)
			return (free(expand_var), perror("cd"), 1);
		free(expand_var);
	}
	else if (chdir(arg) != 0)
		return (perror("cd"), 1);
	return (0);
}

int	builtin_cd(char **args, t_list **env_list)
{
	char	prev_cwd[1024];
	char	next_cwd[1024];
	int		ret;

	if (!getcwd(prev_cwd, sizeof(prev_cwd)))
		return (perror("cd"), 1);
	ret = 0;
	if (args[1] && args[2] != NULL)
		return (print_prompt("cd: too many arguments", 2), 1);
	else if (args[1] == NULL)
		ret = home_path(env_list);
	else if (args[1])
		ret = folder_path(args[1], env_list);
	if (ret == 0)
	{
		if (getcwd(next_cwd, sizeof(next_cwd)))
		{
			update_path("OLDPWD", prev_cwd, env_list);
			update_path("PWD", next_cwd, env_list);
		}
		else
			return (perror("cd"), 1);
	}
	return (ret);
}
