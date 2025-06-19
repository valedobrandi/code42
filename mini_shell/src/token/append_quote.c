/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:03:31 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/18 16:30:33 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "libft.h"
#include "parsedef.h"

void	single_quote(t_get_token *t)
{
	t->i++;
	while (t->str[t->i] != SINGLE_QUOTE)
	{
		t->tmp[t->n] = t->str[t->i];
		t->i++;
		t->n++;
	}
	if (t->str[t->i] == SINGLE_QUOTE)
		t->i++;
}

static int	variable_expand(char cur, char next)
{
	return (cur == DOLLAR && next != '?' && next != SPACE && next != '\0'
		&& next != DOUBLE_QUOTE);
}

int	double_quote(t_get_token *t, t_list *env_list)
{
	t->i++;
	while (t->str[t->i] != DOUBLE_QUOTE)
	{
		if (variable_expand(t->str[t->i], t->str[t->i + 1]))
		{
			t->i++;
			t->tmp = append(t, env_list);
			if (t->tmp == NULL)
				return (1);
		}
		else if (t->str[t->i] == DOLLAR && t->str[t->i + 1] == '?')
		{
			t->tmp[t->n++] = '\x1F';
			t->i += 2;
		}
		else
			t->tmp[t->n++] = t->str[t->i++];
	}
	if (t->str[t->i] == DOUBLE_QUOTE)
		t->i++;
	return (0);
}

int	no_quote(t_get_token *t, t_list *env_list)
{
	if (variable_expand(t->str[t->i], t->str[t->i + 1]))
	{
		t->i++;
		t->tmp = append(t, env_list);
		if (t->tmp == NULL)
			return (-1);
	}
	else if (t->str[t->i] == DOLLAR && t->str[t->i + 1] == '?')
	{
		t->tmp[t->n++] = '\x1F';
		t->i += 2;
	}
	else
		t->tmp[t->n++] = t->str[t->i++];
	return (0);
}
