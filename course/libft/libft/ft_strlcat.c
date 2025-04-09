/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 08:37:43 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/04 08:46:29 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *restrict src, size_t dsize)
{
	size_t	size_src;
	size_t	size_dst;
	size_t	index;

	size_src = 0;
	while (src[size_src] != '\0')
		size_src++;
	size_dst = 0;
	while (dst[size_dst] != '\0')
		size_dst++;
	if (dsize <= size_dst)
		return (dsize + size_src);
	index = 0;
	while (index < (dsize - size_dst - 1) && src[index] != '\0')
	{
		dst[size_dst + index] = src[index];
		index++;
	}
	dst[index + size_dst] = '\0';
	return (size_dst + size_src);
}
