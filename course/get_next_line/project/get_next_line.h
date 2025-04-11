/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:23:17 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/11 13:04:18 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
char	*buffer_line(char *buffer, int bsize);
char	*ft_strncpy(char *dest, char *src, int n);
char	*ft_strdup(const char *s);

# endif
