/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 08:38:07 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/04 10:51:16 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0')
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	little_len;

	little_len = 0;
	if (*little == '\0')
		return ((char *)big);
	if (len <= 0)
		return (NULL);
	while (little[little_len])
		little_len++;
	while (*big && len >= little_len)
	{
		if (*big == *little && ft_strncmp(big, little, little_len) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
