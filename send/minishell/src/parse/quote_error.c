/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:50:00 by ajolivie          #+#    #+#             */
/*   Updated: 2025/06/23 08:30:36 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsedef.h"

static void	printchar_error(char value)
{
	ft_putstr_fd("minishell: unexpected EOF while looking for matching `", 2);
	ft_putchar_fd(value, 2);
	ft_putendl_fd("'", 2);
}

static int	skip_single_quote(char *prompt, int *index, int *single_quote_count)
{
	(*single_quote_count)++;
	(*index)++;
	while (prompt[*index] && prompt[*index] != SINGLE_QUOTE)
		(*index)++;
	if (prompt[*index] == '\0')
		return (1);
	(*single_quote_count)++;
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

static int	parse(int *single_quote_count, int *double_quote_count, char *quote,
		char *prompt)
{
	int	index;

	index = 0;
	while (prompt[index])
	{
		if (prompt[index] == DOUBLE_QUOTE)
		{
			*quote = '"';
			if (skip_double_quote(prompt, &index, double_quote_count))
				break ;
		}
		else if (prompt[index] == SINGLE_QUOTE)
		{
			*quote = '\'';
			if (skip_single_quote(prompt, &index, single_quote_count))
				break ;
		}
		else
			index++;
	}
	return (0);
}

int	quote_error(char *prompt, int *exit_code)
{
	int		double_quote_count;
	int		single_quote_count;
	char	quote;

	double_quote_count = 0;
	single_quote_count = 0;
	parse(&single_quote_count, &double_quote_count, &quote, prompt);
	if (double_quote_count % 2 != 0 || single_quote_count % 2 != 0)
	{
		*exit_code = 2;
		return (printchar_error(quote), 1);
	}
	return (0);
}
