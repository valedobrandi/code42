/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 08:58:29 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/20 10:48:22 by bde-albu         ###   ########.fr       */
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
			print(current->content, 1);
		current = current->next;
	}
}

int	builtin_export(char **args, t_list **env_list)
{
	int	i;
    int ret;
    int exit_code;

	i = 1;
    ret = 0;
    exit_code = ret;
	if (args[1] != NULL)
	{
		while (args[i])
		{
            ret = update_env_list(args[i], env_list);
            if (ret)
                exit_code = ret;
			i++;
		}
	}
	else
		print_alphabetic_order(*env_list, print_export);
	return (exit_code);
}
