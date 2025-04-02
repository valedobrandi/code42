/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:07:55 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/02 10:39:46 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t  ft_strlcpy(char *dst, const char *restrict src, size_t dsize)
{
    size_t i;
    size_t j;

    i = 0;
    while (src[i] != '\0')
        i++;
    if (dsize == 0)
        return (i);
    j = 0;
    while (j < dsize && src[j] != '\0')
    {
        dst[j] = src[j];
        j++;  
    }
    dst[j] = '\0';

    return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *ptr;

	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (s + start), (len));
	return (ptr);
}