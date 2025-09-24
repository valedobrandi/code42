/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:49:19 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/23 09:21:38 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static void	print_env_list(t_list *env_list)
{
	t_list		*current;
	t_init_env	*env;

	current = env_list;
	while (current)
	{
		env = (t_init_env *)current->content;
		if (env->key && env->value && env->export)
			print_env(current->content, 0);
		current = current->next;
	}
}

int	builtin_env(char **args, t_list **env_list)
{
	t_list	*copy;
	int		i;

	i = 1;
	copy = NULL;
	copy = copy_env_list(*env_list);
	if (!copy)
		return (1);
	if (args[1] != NULL)
	{
		while (args[i])
		{
			if (update_env_list(args[i], &copy) == 1)
				return (free_env_list(&copy), 1);
			i++;
		}
	}
	else
		print_env_list(copy);
	free_env_list(&copy);
	return (0);
}
