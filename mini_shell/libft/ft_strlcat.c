/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajolivie <ajolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:49:16 by ajolivie          #+#    #+#             */
/*   Updated: 2025/04/01 13:40:50 by ajolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	di;
	size_t	si;

	si = ft_strlen(src);
	if (!dest && size == 0)
		return (si);
	j = ft_strlen(dest);
	di = j;
	if (size <= di)
		return (size + si);
	i = 0;
	while (src[i] && j + 1 < size)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = 0;
	return (di + si);
}
