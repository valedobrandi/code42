/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:14:01 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/20 14:41:00 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include "minishell.h"

int	pipe_handle(char **strs, int *p)
{
	char	*line;
	int		length;
	int		i;

	i = 1;
	while (*p > 0 && ft_strcmp(strs[*p - 1], "|") == 0)
	{
		ft_putendl_fd("> ", 1);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		length = ft_strlen(line);
		if (length > 0 && line[length - 1] == '\n')
			line[length - 1] = '\0';
		if (parse(line, strs, p) == NULL)
			return (1);
		free(line);
		i++;
	}
	return (0);
}
