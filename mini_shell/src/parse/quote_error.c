/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:50:00 by ajolivie          #+#    #+#             */
/*   Updated: 2025/06/20 08:48:53 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsedef.h"

static int	skip_single_quote(char *prompt, int *index)
{
	(*index)++;
	while (prompt[*index] && prompt[*index] != SINGLE_QUOTE)
		(*index)++;
	if (prompt[*index] == '\0')
		return (1);
	(*index)++;
	return (0);
}

static int	skip_double_quote(char *prompt, int *index, int *double_quote_count)
{
	(*double_quote_count)++;
	(*index)++;
	while (prompt[*index] && prompt[*index] != DOUBLE_QUOTE)
		(*index)++;
	if (prompt[*index] == '\0')
		return (1);
	(*double_quote_count)++;
	(*index)++;
	return (0);
}

int	quote_error(char *prompt)
{
	int	double_quote_count;
	int	index;

	index = 0;
	double_quote_count = 0;
	while (prompt[index])
	{
		if (prompt[index] == DOUBLE_QUOTE)
		{
			if (skip_double_quote(prompt, &index, &double_quote_count))
				return (1);
		}
		else if (prompt[index] == SINGLE_QUOTE)
		{
			if (skip_single_quote(prompt, &index))
				return (1);
		}
		else
			index++;
	}
	if (double_quote_count % 2 != 0)
		return (1);
	return (0);
}
