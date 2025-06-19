/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:56:14 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/18 16:37:12 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "libft.h"
#include "minishell.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	finalize_heredoc(int heredoc_pipe[2])
{
	close(heredoc_pipe[1]);
	dup2(heredoc_pipe[0], STDIN_FILENO);
	close(heredoc_pipe[0]);
}

static int	handle_input_redirection(char *file, int heredoc_pipe[2])
{
	if (redirect_input(file) < 0)
		return (1);
	if (heredoc_pipe[0] != -1)
	{
		close(heredoc_pipe[0]);
		close(heredoc_pipe[1]);
		heredoc_pipe[0] = -1;
		heredoc_pipe[1] = -1;
	}
	return (0);
}

static int	handle_heredoc(char *delimiter, int heredoc_pipe[2])
{
	char	*line;

	if (heredoc_pipe[0] == -1 && pipe(heredoc_pipe) < 0)
		return (perror("pipe"), 1);
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
		write(heredoc_pipe[1], line, ft_strlen(line));
		write(heredoc_pipe[1], "\n", 1);
		free(line);
	}
	return (0);
}

static int	handle_execute(t_redir **redirs, int i, int heredoc_pipe[2])
{
	if (redirs[i]->type == REDIR_HEREDOC)
	{
		if (handle_heredoc(redirs[i]->file, heredoc_pipe) != 0)
			return (1);
	}
	else if (redirs[i]->type == REDIR_IN)
	{
		if (handle_input_redirection(redirs[i]->file, heredoc_pipe) != 0)
			return (1);
	}
	else if (redirs[i]->type == REDIR_OUT)
	{
		if (redirect_output(redirs[i]->file) < 0)
			return (1);
	}
	else if (redirs[i]->type == REDIR_APPEND)
	{
		if (redirect_output_append(redirs[i]->file) < 0)
			return (1);
	}
	return (0);
}

int	apply_redirections(t_redir **redirs)
{
	int	i;
	int	heredoc_pipe[2];

	i = 0;
	heredoc_pipe[0] = -1;
	heredoc_pipe[1] = -1;
	while (redirs[i])
	{
		if (handle_execute(redirs, i, heredoc_pipe))
			return (1);
		i++;
	}
	if (heredoc_pipe[0] != -1)
		finalize_heredoc(heredoc_pipe);
	return (0);
}
