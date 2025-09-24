/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajolivie <ajolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 08:19:43 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/18 11:34:19 by ajolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdlib.h>

void	free_env(void *content)
{
	t_init_env	*env;

	env = (t_init_env *)content;
	if (env->key)
		free(env->key);
	if (env->sing)
		env->sing = '\0';
	if (env->value)
		free(env->value);
	free(env);
}

void	free_env_list(t_list **env_list)
{
	ft_lstclear(env_list, free_env);
	*env_list = NULL;
}
