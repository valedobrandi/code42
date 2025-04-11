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

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	index = 0;
	static int	bytes_read = 0;
	//int			bsize;
	//char		*line;

	//bsize = BUFFER_SIZE;
	while (1)
	{
		if (index >= bytes_read)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			printf("%s", buffer);
		}
		if (bytes_read <= 0)
			return (NULL);
		index++;
	}
}
