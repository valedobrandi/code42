/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajolivie <ajolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:17:31 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/18 11:37:07 by ajolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdlib.h>

void	print(void *content)
{
	t_init_env	*env;

	if (!content)
		return ;
	env = (t_init_env *)content;
	ft_putstr_fd(env->key, 1);
	ft_putstr_fd("=", 1);
	ft_putendl_fd(env->value, 1);
}

void	print_alphabetic_order(t_list *env_list,
		void (*print)(t_list *env_list, char c))
{
	char	c;

	c = 'A' - 1;
	while (++c <= 'Z')
		print(env_list, c);
	c = 'a' - 1;
	while (++c <= 'z')
		print(env_list, c);
	c = '0' - 1;
	while (++c <= '9')
		print(env_list, c);
	print(env_list, '_');
}
