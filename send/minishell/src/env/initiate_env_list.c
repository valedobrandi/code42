/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_env_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:52:18 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/23 10:28:02 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

static int	create_oldpw(t_list **env_list)
{
	t_init_env	*env;
	t_init_env	*find;

	env = NULL;
	find = find_variable(*env_list, "OLDPWD");
	if (!find)
	{
		env = malloc(sizeof(t_init_env));
		if (!env)
			return (1);
		*env = allocate_env("OLDPWD=", 1);
		ft_lsadd_front(env_list, ft_lstnew(env));
		return (0);
	}
	return (0);
}

t_list	*init_env(char **envp)
{
	t_init_env	*env;
	t_list		*env_list;
	int			i;

	env_list = NULL;
	i = 0;
	while (envp[i])
	{
		env = malloc(sizeof(t_init_env));
		if (!env)
			return (NULL);
		*env = allocate_env(envp[i], 1);
		if (env->sing)
			ft_lsadd_front(&env_list, ft_lstnew(env));
		else
			free(env);
		i++;
	}
	create_oldpw(&env_list);
	return (env_list);
}
