/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:45:34 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/11 14:30:32 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "libft.h"
#include "parse_def.h"
#include <stdlib.h>

static char	*get_token(char *str, char *tmp, int size)
{
	t_get_token	t;

	ft_memset(&t, 0, sizeof(t_get_token));
	t.str = str;
	t.tmp = tmp;
	t.size = size;
	while (t.str[t.i] != '\0')
	{
		if (t.str[t.i] == SINGLE_QUOTE)
			single_quote(&t);
		else if (t.str[t.i] == DOUBLE_QUOTE)
			double_quote(&t);
		else
			no_quote(&t);
	}
	t.tmp[t.n] = '\0';
	return (t.tmp);
}

static t_token_type	get_type(char *str)
{
	if (str[0] == '>' && str[1] == '>')
		return (TOKEN_REDIRECT_APPEND);
	else if (str[0] == '<' && str[1] == '<')
		return (TOKEN_HEREDOC);
	else if (str[0] == '|')
		return (TOKEN_PIPE);
	else if (str[0] == '<')
		return (TOKEN_REDIRECT_IN);
	else if (str[0] == '>')
		return (TOKEN_REDIRECT_OUT);
	else
		return (TOKEN_WORD);
}

static int	create_token_list(int size, char **strs, t_token_list *token_list)
{
	char	*tmp;
	int length;
	int		i;

	i = 0;
	while (i < size)
	{
		if (strs[i] != NULL)
		{
			token_list->tokens[i].type = get_type(strs[i]);
			length = ft_strlen(strs[i]);
			tmp = malloc((length + 1) * sizeof(char));
			if (tmp == NULL)
				return (1);
			token_list->tokens[i].value = get_token(strs[i], tmp, length);
			if (token_list->tokens[i].value == NULL)
				return (1);
			token_list->size++;
		}
		i++;
	}
	return (0);
}
t_token_list	*build_tokens(char **strs)
{
	t_token_list	*token_list;
	int				size;

	size = 0;
	while (strs[size])
		size++;
	token_list = malloc(sizeof(t_token_list));
	if (token_list == NULL)
		return (NULL);
	ft_memset(token_list, 0, sizeof(t_token_list));
	token_list->tokens = malloc(sizeof(t_token) * size);
	if (token_list->tokens == NULL)
		return (free(token_list), NULL);
	if (create_token_list(size, strs, token_list) == 1)
		return (free_token_list(token_list), NULL);
	return (token_list);
}
