/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:17:47 by ajolivie          #+#    #+#             */
/*   Updated: 2025/06/20 11:04:32 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	return_process(int is_child_process, int exit_code)
{
	if (is_child_process)
		exit(exit_code);
	return (exit_code);
}

static int	validate_exit_arg(char *arg)
{
	if (!arg)
		return (0);
	if (*arg == '+' || *arg == '-')
		arg++;
	while (*arg)
	{
		if (*arg == '\'' || *arg == '\"')
			arg++;
		if (!ft_isdigit(*arg))
			return (1);
		arg++;
	}
	return (0);
}

int	builtin_exit(char **args, int is_child_process)
{
	long long	exit_value;

	exit_value = 0;
	if (!args[1])
	{
		ft_putendl_fd("exit", 2);
		return (return_process(is_child_process, 0));
	}
	if (validate_exit_arg(args[1]))
	{
		ft_putendl_fd("exit: numeric argument required", 2);
		return (return_process(is_child_process, 2));
	}
	if (args[2])
	{
		ft_putendl_fd("exit: too many arguments", 2);
		return (1);
	}
	exit_value = ft_atoi(args[1]) % 256;
	return (return_process(is_child_process, (unsigned char)exit_value));
}
