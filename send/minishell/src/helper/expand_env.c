/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 08:26:58 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/23 08:27:01 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

char	*expand_env(char *arg, t_list **env_list)
{
	t_init_env	*home;
	char		*expand;
	int			length;

	length = ft_strlen(arg);
	home = find_variable(*env_list, "HOME");
	if (!home || !home->value)
		return (ft_putendl_fd("cd: HOME not set", 2), NULL);
	length += ft_strlen(home->value);
	expand = malloc(length + 1);
	if (!expand)
		return (NULL);
	ft_strcpy(expand, home->value);
	ft_strcat(expand, arg);
	return (expand);
}
