/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:17:31 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/23 09:06:06 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	print_env(void *content, int type)
{
	t_init_env	*env;

	if (!content)
		return ;
	env = (t_init_env *)content;
	if (type)
	{
		if (env->value)
			ft_printf("declare -x %s=\"%s\"\n", env->key, env->value);
		else
			ft_printf("declare -x %s\n", env->key);
	}
	else
	{
		if (env->value)
			ft_printf("%s=%s\n", env->key, env->value);
		else
			ft_printf("%s=\n", env->key);
	}
}

void	print_alphabetic_order(t_list *env_list,
		void (*print_env)(t_list *env_list, char c))
{
	char	c;

	c = 'A' - 1;
	while (++c <= 'Z')
		print_env(env_list, c);
	c = 'a' - 1;
	while (++c <= 'z')
		print_env(env_list, c);
	c = '0' - 1;
	while (++c <= '9')
		print_env(env_list, c);
	print_env(env_list, '_');
}
