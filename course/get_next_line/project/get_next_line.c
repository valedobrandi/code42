/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:15:50 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/11 15:09:39 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
  static t_get_next_line *r;
  char *result;
  int index;
  int b;

  if (!r)
  {
    r = malloc(sizeof(t_get_next_line));
    if (r == NULL)
      return (NULL);
    r->index = 0;
    r->bytes_read = 0;
  }
    r->total_buffer = 0;
    r->line = NULL;
    r->buff = NULL;
  while (1)
  {

    if (r->index >= r->bytes_read)
    {
      r->bytes_read = read(fd, r->buffer, BUFFER_SIZE);
      if (r->bytes_read <= 0)
      {
        if (r->line && r->line[0] != '\0')
        {
          result = r->line;
          free(r);
          return (result);
        }
        if (r->line) 
            free(r->line);
        free(r);
        r = NULL;
        return (NULL);
      }
      r->index = 0;
    }
    index = 0;
    while (r->index < r->bytes_read)
    {
      r->buff = malloc(r->total_buffer + 2);
      if (!r->buff)
        return (NULL);
      if (r->line)
      {
        b = 0;
        while (b < r->total_buffer)
        {
          r->buff[b] = r->line[b];
          b++;
        }
        free(r->line);
      }
      r->buff[r->total_buffer] = r->buffer[r->index];
      r->buff[r->total_buffer + 1] = '\0';
      r->line = r->buff;
      r->total_buffer++;
      index++;
      if (r->buffer[r->index] == '\n')
      {
        r->index++;
        return (r->line);
      }
      r->index++;
    }
  }

  return (NULL);
}
