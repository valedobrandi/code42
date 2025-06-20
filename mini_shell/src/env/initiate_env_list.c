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
		if (env->sing != NULL)
			ft_lsadd_front(&env_list, ft_lstnew(env));
		else
			free(env);
		i++;
	}
	return (env_list);
}
