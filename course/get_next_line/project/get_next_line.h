/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:23:17 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/14 17:47:34 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_get_next_line_static
{
    int index;
    char buffer[BUFFER_SIZE];
} t_get_next_line_static;

typedef struct s_get_next_line_vars
{
    char *line;
    int bytes_read;
    int index;
    int buff;
} t_get_next_line_vars;
typedef struct s_get_next_line_static
{
	int		index;
	char	buffer[BUFFER_SIZE];
	/* 	int		bytes_read;
		int	total_buffer;
		char	*buff; */
}			t_get_next_line_static;

typedef struct s_get_next_line_vars
{
	int		bytes_read;
	char	*line;
	char	line_buffer;
	int		total_buffer;
}			t_get_next_line_vars;

char *get_next_line(int fd);
void *ft_memcpy(void *dest, const void *src, size_t n);
char *ft_relloc(char *line, int buff, int index);
char		*get_next_line(int fd);
int			read_file(int fd, t_get_next_line_static file,
				t_get_next_line_vars vars);
char		*append_line(t_get_next_line_static file,
				t_get_next_line_vars vars);

/* int			init_struct(t_get_next_line **file);
int			read_file(int fd, t_get_next_line *file);
void		copy_line_to_buffer(char *line, t_get_next_line *file);
int			callback_new_line(t_get_next_line *file);
char	*append_line(t_get_next_line *file, char *line); */

#endif
