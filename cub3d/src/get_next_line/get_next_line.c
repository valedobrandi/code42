/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajolivie <ajolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:47:23 by ajolivie          #+#    #+#             */
/*   Updated: 2025/04/24 12:03:25 by ajolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **storage)
{
	char	*newline;
	char	*line;
	char	*rest;

	newline = ft_strchr(*storage, '\n');
	if (newline)
	{
		line = ft_substr(*storage, 0, newline - *storage + 1);
		rest = ft_strdup(newline + 1);
		free(*storage);
		*storage = rest;
		return (line);
	}
	else if (**storage)
	{
		line = ft_strdup(*storage);
		free(*storage);
		*storage = NULL;
		return (line);
	}
	free(*storage);
	*storage = NULL;
	return (NULL);
}

static char	*read_and_store(char *st, int fd)
{
	char	*buf;
	ssize_t	r;
	char	*tmp;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	r = 1;
	while (!ft_strchr(st, '\n') && r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r <= 0)
			break ;
		buf[r] = '\0';
		tmp = ft_strjoin_gnl(st, buf);
		if (!tmp)
			return (free(buf), NULL);
		st = tmp;
	}
	free(buf);
	return (st);
}

char	*get_next_line(int fd)
{
	static char	*st = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	st = read_and_store(st, fd);
	if (!st || !*st)
		return (free(st), st = NULL, NULL);
	return (extract_line(&st));
}
