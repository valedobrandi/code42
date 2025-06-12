/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 08:58:29 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/11 12:46:21 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	print_export(t_list *env_list, char c)
{
	t_list		*current;
	t_init_env	*env;

	current = env_list;
	while (current)
	{
		env = (t_init_env *)current->content;
		if (env->key && env->key[0] == c && env->export)
			print(current->content);
		current = current->next;
	}
}
int	builtin_export(char **args, t_list *env_list)
{
	int i;

	i = 1;
	if (args[1] != NULL)
	{
		while (args[i])
		{
			if (update_env_list(args[i], &env_list) == 1)
				return (1);
			i++;
		}
	}
	else
		print_alphabetic_order(env_list, print_export);
	return (0);
}