/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajolivie <ajolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:43:49 by ajolivie          #+#    #+#             */
/*   Updated: 2025/06/23 11:47:12 by ajolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "libft.h"
#include "ft_printf.h"
#include "minishell.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

static void	print_redirect_error(const char *filename)
{
	ft_putstr_fd("minishell: ", 2);
	if (filename && filename[0])
	{
		ft_putstr_fd((char *)filename, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd((char *)strerror(errno), 2);
	}
	else
		ft_putstr_fd("ambiguous redirect", 2);
	ft_putchar_fd('\n', 2);
}

int	redirect_input(const char *filename)
{
	int	fd;

	if (!filename || filename[0] == '\0')
	{
		print_redirect_error(filename);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		print_redirect_error(filename);
		return (-1);
	}
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		close(fd);
		perror("minishell: dup2");
		return (-1);
	}
	close(fd);
	return (0);
}

int	redirect_output(const char *filename)
{
	int	fd;

	if (!filename || filename[0] == '\0')
	{
		print_redirect_error(filename);
		return (-1);
	}
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		print_redirect_error(filename);
		return (-1);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		close(fd);
		perror("minishell: dup2");
		return (-1);
	}
	close(fd);
	return (0);
}

int	redirect_output_append(const char *filename)
{
	int	fd;

	if (!filename || filename[0] == '\0')
	{
		print_redirect_error(filename);
		return (-1);
	}
	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		print_redirect_error(filename);
		return (-1);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		close(fd);
		perror("minishell: dup2");
		return (-1);
	}
	close(fd);
	return (0);
}

int	apply_heredoc(const char *delimiter)
{
	int		pipe_fd[2];
	char	*line;

	if (!delimiter || pipe(pipe_fd) < 0)
		return (-1);
	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		write(pipe_fd[1], line, ft_strlen(line));
		write(pipe_fd[1], "\n", 1);
		free(line);
	}
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}
