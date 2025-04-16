/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:23:17 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/16 15:05:49 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_get_next_line_static
{
	int		index;
	char	buffer[BUFFER_SIZE];
}			t_get_next_line_static;

typedef struct s_get_next_line_vars
{
	char	*line;
	int		bytes_read;
	int		index;
	int		buff;
}			t_get_next_line_vars;

char		*get_next_line(int fd);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_relloc(char *line, int buff, int index);
#endif
