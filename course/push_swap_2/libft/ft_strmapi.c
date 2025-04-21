/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 08:37:57 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/04 10:55:16 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*ptr;

	if (!s || !f)
		return (NULL);
	index = ft_strlen((char *)s);
	ptr = (char *)malloc((index + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		ptr[index] = f(index, s[index]);
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}
