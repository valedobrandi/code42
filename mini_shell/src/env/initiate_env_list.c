/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_env_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajolivie <ajolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:52:18 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/18 11:29:22 by ajolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdlib.h>

static t_init_env *create_oldpw()
{
    t_init_env	*env;

    env = malloc(sizeof(t_init_env));
		if (!env)
			return (NULL);
    *env = allocate_env("OLDPWD=", 1);
    return (env);
}

t_list	*init_env(char **envp)
{
	t_init_env	*env;
    t_init_env	*oldpwd;
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
    oldpwd = create_oldpw();
    if (!oldpwd)
        return (NULL);
    ft_lsadd_front(&env_list, ft_lstnew(oldpwd));
	return (env_list);
}
