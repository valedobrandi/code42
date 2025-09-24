/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:57:35 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/23 08:30:08 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

t_init_env	allocate_env(char *arg, bool export)
{
	t_init_env	t;
	char		*has_sing;

	t.sing = '\0';
	ft_memset(&t, 0, sizeof(t_init_env));
	has_sing = ft_strchr(arg, '=');
	if (has_sing)
	{
		t.k_len = has_sing - arg;
		t.key = ft_substr(arg, 0, t.k_len);
		t.value = ft_strtrim(has_sing + 1, " \t\r\n");
		t.sing = '=';
	}
	else
	{
		t.key = ft_strdup(arg);
		t.value = ft_strdup("");
	}
	t.export = export;
	return (t);
}
