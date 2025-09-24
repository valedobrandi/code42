/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:51:56 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/20 14:20:20 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdlib.h>

static int	is_valid(char c)
{
	return (ft_isalnum(c) || c == '_');
}

static int	get_length(char *input)
{
	int	len;

	len = 0;
	if (input && ft_isdigit(input[0]) && input[0] != '_')
		len++;
	while (input && input[len] && is_valid(input[len]))
		len++;
	return (len);
}

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
	free(expand);
	t->n += expand_len;
	t->i += get_length(t->str + t->i);
	return (t->tmp);
}
