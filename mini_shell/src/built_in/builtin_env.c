/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:49:19 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/10 14:07:34 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 08:58:29 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/06 15:03:59 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	print_env(t_list *env_list, char c)
{
	t_list		*current;
	t_init_env	*env;

	current = env_list;
	while (current)
	{
		env = (t_init_env *)current->content;
		if (env->key && env->key[0] == c && env->value && env->export)
			print(current->content);
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
			if (update_env_list(args[i], env_list) == 1)
				return (1);
			i++;
		}
		free_env_list(env_list);
	}
	else
		print_alphabetic_order(*env_list, print_env);
	return (0);
}
