/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 08:19:43 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/11 09:33:23 by bde-albu         ###   ########.fr       */
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
		env->sing = NULL;
	if (env->value)
		free(env->value);
	free(env);
}

void free_env_list(t_list **env_list)
{
	ft_lstclear(env_list, free_env);
	*env_list = NULL;
}
