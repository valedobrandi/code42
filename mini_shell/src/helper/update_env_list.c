/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:49:54 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/20 11:38:24 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

void	update(t_init_env *new_env, t_init_env *list_env)
{
	if (new_env->sing && list_env->sing)
	{
		if (list_env->value)
			free(list_env->value);
		if (new_env->value)
			list_env->value = ft_strdup(new_env->value);
		else
			list_env->value = NULL;
		list_env->export = true;
	}
	else if (!new_env->sing)
		list_env->export = true;
}

t_init_env	*find_variable(t_list *env_list, char *key)
{
	t_list		*current;
	t_init_env	*env;

	current = env_list;
	while (current)
	{
		env = (t_init_env *)current->content;
		if (env->key && ft_strcmp(key, env->key) == 0)
			return (env);
		current = current->next;
	}
	return (NULL);
}

static int	validate_exit_arg(char *key)
{
	if (!ft_isalpha(*key) && *key != '_')
		return (1);
	key++;
	while (*key)
	{
		if (!ft_isalnum(*key) && *key != '_')
			return (1);
		key++;
	}
	return (0);
}

int	update_env_list(char *arg, t_list **env_list)
{
	t_init_env	*arg_env;
	t_init_env	*list_env;

	arg_env = malloc(sizeof(t_init_env));
	if (!arg_env)
		return (1);
	*arg_env = allocate_env(arg, true);
	if (validate_exit_arg(arg_env->key))
	{
		ft_putendl_fd("export: not a valid identifier", 2);
		free_env(arg_env);
		return (1);
	}
	list_env = find_variable(*env_list, arg_env->key);
	if (list_env)
	{
		update(arg_env, list_env);
		free_env(arg_env);
	}
	else
		ft_lsadd_front(env_list, ft_lstnew(arg_env));
	return (0);
}
