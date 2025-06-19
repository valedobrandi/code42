/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:46:42 by ajolivie          #+#    #+#             */
/*   Updated: 2025/06/18 16:38:25 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static char	**get_paths(char **envp)
{
	if (!envp)
		return (NULL);
	while (*envp && ft_strncmp(*envp, "PATH=", 4) != 0)
		envp++;
	if (!*envp)
		return (NULL);
	return (ft_split(*envp + 5, ':'));
}

static char	*try_paths(char **paths, char *cmd)
{
	int		i;
	char	*full_path;
	size_t	len_path;
	size_t	len_cmd;

	i = 0;
	len_cmd = ft_strlen(cmd);
	if (!cmd || !*cmd)
		return (NULL);
	while (paths[i])
	{
		len_path = ft_strlen(paths[i]);
		full_path = malloc(len_path + 1 + len_cmd + 1);
		if (!full_path)
			return (NULL);
		ft_strlcpy(full_path, paths[i], len_path + 1);
		ft_strlcat(full_path, "/", len_path + 2);
		ft_strlcat(full_path, cmd, len_path + len_cmd + 2);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;

	if (!cmd || *cmd == '\0')
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	paths = get_paths(envp);
	if (!paths)
		return (NULL);
	path = try_paths(paths, cmd);
	free_split(paths);
	return (path);
}

void	free_split(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}
