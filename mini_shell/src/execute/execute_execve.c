/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_execve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:50:13 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/20 09:11:46 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

static void	is_directory(char *cmd, char *bin_path, char **env)
{
	struct stat	st;

	if (stat(bin_path, &st) == 0 && S_ISDIR(st.st_mode))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": Is a directory", 2);
		if (bin_path != cmd)
			free(bin_path);
		free_array(env);
		exit(126);
	}
}

void	execute_execve(char **args, char *cmd, char *bin_path, char **env)
{
	int	err;

	execve(bin_path, args, env);
	err = 126;
	if (errno == ENOENT)
		err = 127;
	else if (errno == EACCES)
		err = 126;
	is_directory(cmd, bin_path, env);
	perror("execve");
	if (bin_path && bin_path != cmd)
		free(bin_path);
	free_array(env);
	exit(err);
}
