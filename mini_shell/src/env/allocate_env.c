/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:57:35 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/10 12:58:22 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

t_init_env	allocate_env(char *envp, bool export)
{
	t_init_env	t;

	ft_memset(&t, 0, sizeof(t_init_env));
	t.sing = ft_strchr(envp, '=');
	if (t.sing)
	{
		t.k_len = t.sing - envp;
		t.key = ft_substr(envp, 0, t.k_len);
		t.value = ft_strdup(t.sing + 1);
		t.export = export;
		return (t);
	}
	t.sing = NULL;
	return (t);
}
