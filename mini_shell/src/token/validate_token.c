/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:06:16 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/18 17:06:17 by bde-albu         ###   ########.fr       */
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

int	next_token(t_token_list *token_list, int i)
{
	if (i == 0 || i == token_list->size - 1)
		return (print_prompt("Error: pipe at invalid position", 2), 1);
	if (ft_strcmp("|", token_list->tokens[i].value) != 0)
		return (print_prompt("Error: invalid double pipe", 2), 1);
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

int	token_validation(t_token_list *token_list)
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
			if (next_token(token_list, i))
				return (1);
		}
		else if (is_redirection(current_token))
		{
			if (!is_operator_valid(current_token, token_list->tokens[i].value))
				return (print_prompt("invalid redirection operator", 2), 1);
			if (!is_valid_redirection_target(token_list, i))
				return (print_prompt("invalid redirection syntax", 2), 1);
		}
		i++;
	}
	return (0);
}
