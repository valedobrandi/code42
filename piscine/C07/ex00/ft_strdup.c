/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:09:40 by bde-albu          #+#    #+#             */
/*   Updated: 2025/02/11 11:23:23 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_strlcpy(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i += 1;
	}
}

char	*ft_strdup(char *src)
{
	int		n;
	char	*ptr;

	n = 0;
	while (src[n])
		n += 1;
	ptr = (char *)malloc(n + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, src);
	return (ptr);
}
/*
int    main(void)
{
    char source[] = "GeeksForGeeks";

    char    *target = ft_strdup(source);
    for (int i = 0;i < 11; i += 1)
        printf("%c", target[i]);
    printf("\n");
}
*/
