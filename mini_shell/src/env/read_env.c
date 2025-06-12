/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:52:29 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/06 10:52:30 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_valid(char c)
{
	return (ft_isalnum(c) || c == '_');
}

int	ft_env_length(char *env)
{
	int	i;

	i = 0;
	while (env[i] && is_valid(env[i]))
		i++;
	return (i);
}

char	*get_variable(char *env)
{
	int length;
	char *input;

	length = ft_env_length(env);
	input = malloc((length + 1) * sizeof(char));
	if (input == NULL)
		return (ft_strdup(""));
	ft_strncpy(input, env, length);

	/*  IMPLEMENT THE GET TO THE ACTUAL ENV ----> getenv(input)*/

	return (input);
}