/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_execve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:50:13 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/18 16:39:33 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void	execute_execve(char **args, char *cmd, char *bin_path, char **env)
{
	int	err;

	execve(bin_path, args, env);
	err = 126;
	if (errno == ENOENT)
		err = 127;
	else if (errno == EACCES)
		err = 126;
	perror("execve");
	if (bin_path && bin_path != cmd)
		free(bin_path);
	free_array(env);
	exit(err);
}
