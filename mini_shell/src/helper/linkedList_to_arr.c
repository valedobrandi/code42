/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedList_to_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajolivie <ajolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 08:12:16 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/18 11:39:08 by ajolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

static char	*allocate_string(void *content)
{
	t_init_env	*env;
	int			size;
	char		*str;

	env = (t_init_env *)content;
	size = 0;
	if (env->key)
		size += ft_strlen(env->key);
	if (env->sing)
		size++;
	if (env->value)
		size += ft_strlen(env->value);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[0] = '\0';
	if (env->key)
		ft_strcat(str, env->key);
	if (env->sing && *(env->sing) == '=')
		ft_strcat(str, "=");
	if (env->value)
		ft_strcat(str, env->value);
	return (str);
}

static int	get_list(t_list *env_list, char **envp)
{
	t_list	*current;
	int		i;

	i = 0;
	current = env_list;
	while (current)
	{
		envp[i] = allocate_string(current->content);
		if (!envp[i])
		{
			free_array(envp);
			return (1);
		}
		i++;
		current = current->next;
	}
	envp[i] = NULL;
	return (0);
}

char	**linkedlist_to_arr(t_list *env_list)
{
	char	**envp;
	int		size;

	size = ft_lstsize(env_list);
	envp = malloc(sizeof(char *) * (size + 1));
	if (!envp)
		return (NULL);
	if (get_list(env_list, envp))
		return (NULL);
	return (envp);
}
