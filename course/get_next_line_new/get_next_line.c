/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:15:50 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/22 16:51:15 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *store_buffer(int fd, char *buffer, int bytes_reader)
{
    char *temp_buffer;

    temp_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!temp_buffer)
        return (NULL);
    while (bytes_reader > 0 && !ft_strchr(buffer, '\n'))
    {
        bytes_reader = read(fd, temp_buffer, BUFFER_SIZE);
        if (bytes_reader == -1)
        {
            free(buffer);
            free(temp_buffer);
            return (NULL);
        }
        buffer[bytes_reader] = '\0';
        temp_buffer = ft_strjoin(buffer, temp_buffer);
        if (!temp_buffer)
        {
            free(buffer);
            return (NULL);
        }
    }
    free(temp_buffer);
    return (buffer);
}

char *get_line(char *buffer)
{
    if (!buffer || buffer[0] == '\0')
        return (NULL);
}

char *get_next_line(int fd)
{
    static char *buffer;
    int bytes_reader;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    bytes_reader = 1;
    buffer = store_buffer(fd, buffer, bytes_reader);
    line = get_line(buffer);
    buffer = update_buffer(buffer);
    return (line);
}
