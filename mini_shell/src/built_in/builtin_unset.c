/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:53:12 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/10 09:15:18 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

void	del(void *content)
{
	t_init_env	*env;

	env = (t_init_env *)content;
	free(env->key);
	free(env->value);
	free(env);
}
void	remove(char *arg, t_list **env_list)
{
	t_list		*node;
	t_list		*prev;
	t_list		*next;
	t_init_env	*env;

	node = *env_list;
	prev = NULL;
	while (node)
	{
		next = node->next;
		env = (t_init_env *)node->content;
		if (env->key && (ft_strcmp(arg, env->key) == 0))
		{
			if (prev == NULL)
				*env_list = next;
			else
				prev->next = next;
			ft_lstdelone(node, del);
			return ;
		}
		else
			prev = node;
		node = next;
	}
}

int	builtin_unset(char **args, t_list **env_list)
{
	int	i;

	i = 1;
	while (args[i])
	{
		remove(args[i], env_list);
		i++;
	}
	return (0);
}
