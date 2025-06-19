/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajolivie <ajolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:52:29 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/18 11:27:50 by ajolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

static int	is_valid(char c)
{
	return (ft_isalnum(c) || c == '_');
}

int	var_length(char *input)
{
	int	len;

	len = 0;
	while (input && input[len] && is_valid(input[len]))
		len++;
	return (len);
}

char	*extract(char *input)
{
	char	*var;
	int		len;

	len = var_length(input);
	var = malloc(len + 1);
	if (!var)
		return (NULL);
	ft_strlcpy(var, input, len + 1);
	return (var);
}

char	*get_variable(char *input, t_list *envp)
{
	int			length;
	char		*output;
	char		*var;
	t_init_env	*find;

	var = extract(input);
	if (!var)
		return (NULL);
	find = find_varible(envp, var);
	free(var);
	if (find == NULL)
		return (ft_strdup(""));
	if (find->value)
		length = ft_strlen(find->value);
	else
		length = 0;
	output = malloc(length + 1);
	if (output == NULL)
		return (ft_strdup(""));
	ft_strncpy(output, find->value, length);
	output[length] = '\0';
	return (output);
}
