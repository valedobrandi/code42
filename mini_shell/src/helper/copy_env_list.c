/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:57:52 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/10 14:11:03 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

int	deep_copy(t_init_env **dest, const t_init_env *src)
{
	(*dest)->k_len = src->k_len;
	(*dest)->export = src->export;
	if (src->sing)
	{
		(*dest)->sing = ft_strdup(src->sing);
		if (!(*dest)->sing)
			return (free(*dest), 1);
	}
	if (src->key)
	{
		(*dest)->key = ft_strdup(src->key);
		if (!(*dest)->key)
			return (free((*dest)->sing), free(*dest), 1);
	}
	if (src->value)
	{
		(*dest)->value = ft_strdup(src->value);
		if (!(*dest)->value)
			return (free((*dest)->sing), free((*dest)->key), free(*dest), 1);
	}
	return (0);
}

t_init_env	*copy_init_env(const t_init_env *src)
{
	t_init_env	*dest;

	if (!src)
		return (NULL);
	dest = malloc(sizeof(t_init_env));
	if (!dest)
		return (NULL);
	ft_memset(dest, 0, sizeof(t_init_env));
	if (deep_copy(&dest, src) == 1)
		return (NULL);
	return (dest);
}

t_list	*copy_env_list(t_list *env_list)
{
	t_init_env	*node;
	t_list		*current;
	t_list		*dest_list;

	if (!env_list)
		return (NULL);
	dest_list = malloc(sizeof(dest_list));
	if (!dest_list)
		return (NULL);
	current = env_list;
	while (current)
	{
		node = copy_init_env((t_init_env *)current->content);
		if (!node)
			free_env_list(&dest_list);
		ft_lsadd_front(&dest_list, ft_lstnew(node));
		current = current->next;
	}
	return (dest_list);
}
