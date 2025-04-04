/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 08:38:13 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/04 10:15:23 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = ((void *)0);
	while (*s != '\0')
	{
		if (*s == (char)c)
			ptr = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (ptr);
}
