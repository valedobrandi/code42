/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:03:31 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/04 11:25:57 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "libft.h"
#include "parse_def.h"

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

static int	is_dollar_mark(char cur, char next)
{
	return (cur == DOLLAR && next == '?');
}

int	double_quote(t_get_token *t)
{
	t->i++;
	while (t->str[t->i] != DOUBLE_QUOTE)
	{
		if (t->str[t->i] == '$' && t->str[t->i + 1] != '?')
		{
			t->i++;
			t->tmp = append(t);
			if (t->tmp == NULL)
				return (1);
		}
		else if (is_dollar_mark(t->str[t->i], t->str[t->i + 1]))
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

int	no_quote(t_get_token *t)
{
	if (t->str[t->i] == '$' && t->str[t->i + 1] != '?')
	{
		t->i++;
		t->tmp = append(t);
		if (t->tmp == NULL)
			return (-1);
	}
	else if (is_dollar_mark(t->str[t->i], t->str[t->i + 1]))
	{
		t->tmp[t->n++] = '\x1F';
		t->i += 2;
	}
	else
		t->tmp[t->n++] = t->str[t->i++];
	return (0);
}
