/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:51:56 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/18 17:06:40 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "libft.h"
#include <stdlib.h>

char	*append(t_get_token *t, t_list *env_list)
{
	int		expand_len;
	char	*expand;
	char	*new_tmp;

	expand = get_variable(t->str + t->i, env_list);
	if (expand == NULL)
		return (free(t->tmp), NULL);
	expand_len = ft_strlen(expand);
	new_tmp = ft_realloc(t->tmp, t->size, t->size + expand_len);
	if (new_tmp == NULL)
		return (free(t->tmp), NULL);
	t->tmp = new_tmp;
	t->size = t->size + expand_len;
	ft_strcpy(t->tmp + t->n, expand);
	t->n += expand_len;
	t->i += var_length(t->str + t->i);
	return (t->tmp);
}
