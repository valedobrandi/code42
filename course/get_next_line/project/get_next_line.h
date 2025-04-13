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
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

typedef struct s_get_next_line
{
    char buffer[BUFFER_SIZE];
    int index;
    int bytes_read;
    int total_buffer;
    char *line;
    char *buff;
} t_get_next_line;

char *get_next_line(int fd);
int ft_findchr(char *s, int c);
size_t ft_strlen(const char *s);
size_t ft_strlcpy(char *dst, char *src, size_t dsize);
size_t findchr(char *str, int c, size_t n);
void *ft_memcpy(void *dest, void *src, size_t n);

#endif
