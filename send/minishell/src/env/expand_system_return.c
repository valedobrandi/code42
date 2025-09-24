/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_system_return.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:30:00 by ajolivie          #+#    #+#             */
/*   Updated: 2025/06/23 08:59:15 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*expand(char *arg, int count, char *sys_char)
{
	char	*str;
	char	*dst;
	int		length;
	int		i;

	length = ft_strlen(arg) + count * (ft_strlen(sys_char) - 1);
	str = malloc(length + 1);
	if (str == NULL)
		return (NULL);
	dst = str;
	i = 0;
	while (arg[i])
	{
		if (arg[i] == '\x1F')
		{
			ft_memcpy(dst, sys_char, ft_strlen(sys_char));
			dst += ft_strlen(sys_char);
		}
		else
			*dst++ = arg[i];
		i++;
	}
	*dst = '\0';
	free(sys_char);
	return (str);
}

static char	*expand_system(int sys, char *arg)
{
	char	*sys_char;
	char	*str;
	int		count;
	int		i;

	sys_char = ft_itoa(sys);
	if (!sys_char)
		return (NULL);
	count = 0;
	i = 0;
	while (arg[i])
	{
		if (arg[i] == '\x1F')
			count++;
		i++;
	}
	str = expand(arg, count, sys_char);
	if (str == NULL)
		return (NULL);
	return (str);
}

static void	expand_cdm(int exit_code, char **cmd)
{
	char	*new_cmd;

	new_cmd = NULL;
	if (ft_strchr(*cmd, '\x1F'))
	{
		new_cmd = expand_system(exit_code, *cmd);
		if (!new_cmd)
			return ;
		free(*cmd);
		*cmd = new_cmd;
	}
}

int	expand_system_return(int exit_code, char **args, char **cmd)
{
	char	*new_arg;
	int		i;

	i = 0;
	while (args[i])
	{
		if (ft_strchr(args[i], '\x1F'))
		{
			new_arg = expand_system(exit_code, args[i]);
			if (!new_arg)
				return (1);
			free(args[i]);
			args[i] = new_arg;
		}
		i++;
	}
	expand_cdm(exit_code, cmd);
	return (0);
}
