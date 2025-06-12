/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:43:49 by ajolivie          #+#    #+#             */
/*   Updated: 2025/06/12 11:12:28 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minishell.h"
# include "libft.h"
# include "../gnl/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int	redirect_input(const char *filename, int fd)
{

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int	redirect_output(const char *filename, int fd)
{
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("open");
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	redirect_output_append(const char *filename, int fd)
{
	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		perror("open");
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	apply_heredoc(const char *delimiter, int fd)
{
	char	*line;

	if (pipe(fd) < 0)
		return (perror("pipe"), -1);
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0
			&& line[ft_strlen(delimiter)] == '\n')
		{
			free(line);
			break ;
		}
		write(fd + 1, line, ft_strlen(line));
		free(line);
	}
	close(fd + 1);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int	apply_redirections(t_redir **redis, int fd)
{
	int	ret;

	while (*redis)
	{
		ret = 0;
		if ((*redis)->type == REDIR_IN)
			ret = redirect_input((*redis)->file, fd);
		else if ((*redis)->type == REDIR_OUT)
			ret = redirect_output((*redis)->file, fd);
		else if ((*redis)->type == REDIR_APPEND)
			ret = redirect_output_append((*redis)->file, fd);
		else if ((*redis)->type == REDIR_HEREDOC)
			ret = apply_heredoc((*redis)->file, fd);
		if (ret < 0)
			return (1);
		redis++;
	}
	return (0);
}
