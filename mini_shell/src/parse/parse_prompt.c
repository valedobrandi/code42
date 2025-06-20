/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:16:06 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/19 09:28:28 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "libft.h"
#include "minishell.h"
#include "parsedef.h"
#include <stdlib.h>

static int	get_operator(char *prompt, int *i, int *p, char **strs)
{
	int	length;

	length = 1;
	while (prompt[*i + length] == IN || prompt[*i + length] == OUT || prompt[*i
			+ length] == PIPE)
		length++;
	strs[*p] = malloc((length + 1) * sizeof(char));
	if (strs[*p] == NULL)
		return (1);
	ft_strlcpy(strs[*p], &prompt[*i], length + 1);
	*i += length;
	(*p)++;
	return (0);
}

static int	get_word_length(char *prompt)
{
	int	double_quote;
	int	single_quote;
	int	i;

	double_quote = 0;
	single_quote = 0;
	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == SINGLE_QUOTE && double_quote == 0)
			single_quote = !single_quote;
		else if (prompt[i] == DOUBLE_QUOTE && single_quote == 0)
			double_quote = !double_quote;
		else if (single_quote == 0 && double_quote == 0)
		{
			if (prompt[i] == IN || prompt[i] == OUT || prompt[i] == SPACE
				|| prompt[i] == TAB || prompt[i] == PIPE)
				break ;
		}
		i++;
	}
	return (i);
}

static int	get_word(char *prompt, int *i, int *p, char **strs)
{
	int	length;

	length = get_word_length(&prompt[*i]);
	strs[*p] = malloc((length + 1) * sizeof(char));
	if (strs[*p] == NULL)
		return (1);
	ft_strlcpy(strs[*p], &prompt[*i], length + 1);
	*i += length;
	(*p)++;
	return (0);
}

static int parse_validate(char **strs)
{
    int i = 0;
    while (strs[i])
    {
        if (ft_strcmp(strs[i], "|") == 0)
        {
            if (strs[i + 1] && (ft_strcmp(strs[i + 1], "|") == 0))
                return (ft_putendl_fd("minishell: error syntax", 2), 1);
        }
        i++;
    }
    return (0);
}

char	**parse(char *prompt, char **strs, int *p)
{
	int	i;

	i = 0;
	while (prompt[i])
	{
		while (prompt[i] == SPACE || prompt[i] == TAB)
			i++;
		if (prompt[i] == '\0')
			break ;
		if (prompt[i] == IN || prompt[i] == OUT || prompt[i] == PIPE)
		{
			if (get_operator(prompt, &i, p, strs))
				return (free_array(strs), NULL);
		}
		else
		{
			if (get_word(prompt, &i, p, strs))
				return (free_array(strs), NULL);
		}
	}
	strs[*p] = NULL;
	return (strs);
}

char	**parse_prompt(char *prompt)
{
	char	**strs;
	int		p;

	p = 0;
	strs = malloc(sizeof(char *) * 1024);
	if (!strs)
		return (NULL);
	if (parse(prompt, strs, &p) == NULL)
		return (NULL);
    if (parse_validate(strs))
    {
        return (free_array(strs), NULL);
    }
	if (pipe_handle(strs, &p))
        return (NULL);
	return (strs);
}
