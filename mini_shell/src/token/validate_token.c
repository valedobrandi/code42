/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:06:16 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/20 15:20:16 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "parsedef.h"

int	is_redirection(t_token_type type)
{
	return (type == TOKEN_REDIRECT_IN || type == TOKEN_REDIRECT_OUT
		|| type == TOKEN_REDIRECT_APPEND || type == TOKEN_HEREDOC);
}

int	next_token(t_token_list *token_list, int i, int *exit_code)
{
	if (i == 0 || i == token_list->size - 1)
	{
		*exit_code = 2;
		return (print_prompt("Error: syntax error near unexpected token `|'",
				2), 1);
	}
	return (0);
}

int	is_operator_valid(t_token_type type, char *value)
{
	if (type == TOKEN_REDIRECT_IN)
		return (ft_strcmp("<", value) == 0);
	else if (type == TOKEN_REDIRECT_OUT)
		return (ft_strcmp(">", value) == 0);
	else if (type == TOKEN_REDIRECT_APPEND)
		return (ft_strcmp(">>", value) == 0);
	else if (type == TOKEN_HEREDOC)
		return (ft_strcmp("<<", value) == 0);
	else
		return (1);
}

int	is_valid_redirection_target(t_token_list *list, int i)
{
	if (i + 1 >= list->size)
		return (0);
	if (!list->tokens[i + 1].value)
		return (0);
	if (list->tokens[i + 1].type != TOKEN_WORD)
		return (0);
	if (is_redirection(list->tokens[i + 1].type))
		return (0);
	return (1);
}

int	token_validation(t_token_list *token_list, int *exit_code)
{
	int	current_token;
	int	i;

	i = 0;
	while (i < token_list->size)
	{
		if (!token_list->tokens[i].value)
			return (print_prompt("Error: null token value", 2), 1);
		current_token = token_list->tokens[i].type;
		if (current_token == TOKEN_PIPE)
		{
			if (next_token(token_list, i, exit_code))
				return (1);
		}
		if (is_redirection(current_token) && validate_directions(current_token,
				token_list, i))
				{
					*exit_code = 2;
					return (1);
				}
		i++;
	}
	return (0);
}
