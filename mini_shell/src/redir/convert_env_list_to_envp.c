/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_env_list_to_envp.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:03:38 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/18 16:03:40 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**convert_env_list_to_envp(t_list *env_list)
{
	char	**envp;
	int		size;
	int		i;
	t_list	*tmp;

	size = ft_lstsize(env_list);
	envp = malloc(sizeof(char *) * (size + 1));
	if (!envp)
		return (NULL);
	i = 0;
	tmp = env_list;
	while (tmp)
	{
		envp[i] = ft_strdup((char *)tmp->content);
		if (!envp[i])
		{
			while (i > 0)
				free(envp[--i]);
			return (free(envp), NULL);
		}
		tmp = tmp->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}
