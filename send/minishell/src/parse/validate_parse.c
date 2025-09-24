/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:42:48 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/23 08:59:41 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_redirect(char *value)
{
	if (!value)
		return (0);
	return (!ft_strcmp(value, "<") || !ft_strcmp(value, "<<")
		|| !ft_strcmp(value, ">>") || !ft_strcmp(value, ">>"));
}

static int	pipe_double_error(char **strs, int i)
{
	return ((strs[i + 1] && (ft_strcmp(strs[i + 1], "|") == 0)) || (i == 0
			&& (ft_strcmp(strs[i], "|") == 0) && strs[i + 1] == NULL));
}

int	validate_parse(char **strs, int *exit_code)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (ft_strcmp(strs[i], "|") == 0)
		{
			if (pipe_double_error(strs, i) || is_redirect(strs[i + 1]))
			{
				*exit_code = 2;
				ft_putendl_fd("Error: syntax error near unexpected token `|'",
					2);
				return (1);
			}
		}
		i++;
	}
	return (0);
}
