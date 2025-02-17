/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:37:42 by bde-albu          #+#    #+#             */
/*   Updated: 2025/02/11 11:01:47 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	index;	

	index = 0;
	while (str[index])
		index += 1;
	return (index);
}

char	*ft_strcat(char *dest, char *src)
{
	int	index;
	int	length;

	length = ft_strlen(dest);
	index = 0;
	while (src[index] != '\0')
	{
		dest[length + index] = src[index];
		index += 1;
	}
	return (dest);
}

void	ft_strarrcat(char *str, char **strs, char *sep, int size)
{
	ft_strcat(str, *strs);
	if (size - 1 && *sep)
		ft_strcat(str, sep);
}

int	ft_init(char **str, int size)
{
	if (size == 0)
	{
		*str = malloc(1 * sizeof(char));
		*str[0] = '\0';
		return (1);
	}
	return (0);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		index;
	int		length;

	if (ft_init(&str, size))
		return (str);
	index = 0;
	length = 0;
	while (strs[index])
	{
		length += ft_strlen(strs[index]);
		index += 1;
	}
	if (size > 1)
		length += 1 * (size - 1);
	str = malloc(length * sizeof(char));
	str[0] = '\0';
	while (size)
	{
		ft_strarrcat(str, strs, sep, size);
		size -= 1;
		strs += 1;
	}
	return (str);
}
