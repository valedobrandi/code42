/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:45:29 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/18 16:39:01 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void	validate_path(char *cmd, char *bin_path, char **env)
{
	struct stat	st;

	if (lstat(bin_path, &st) == -1)
	{
		perror("lstat");
		if (bin_path != cmd)
			free(bin_path);
		free_array(env);
		exit(127);
	}
	if (S_ISDIR(st.st_mode))
	{
		ft_putendl_fd("path: command not found", 2);
		if (bin_path != cmd)
			free(bin_path);
		free_array(env);
		exit(127);
	}
}
