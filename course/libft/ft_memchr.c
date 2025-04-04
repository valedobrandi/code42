/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 08:36:20 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/04 08:54:05 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ss;

	ss = (const unsigned char *)s;
	while (n > 0)
	{
		if ((unsigned char)c == *ss)
			return ((void *)ss);
		ss++;
		n--;
	}
	return (((void *)0));
}
