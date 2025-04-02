/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:37:50 by bde-albu          #+#    #+#             */
/*   Updated: 2025/04/02 16:19:20 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	word_length(char *str, char c)
{
	int	count;

	count = 0;
	while (*str == c)
		str++;
	while (str[count] != '\0' && str[count] != c)
		count++;
	return (count);
}
int	count_words(char const *src, char c)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (src[index] != '\0')
	{
		if (src[index] == c)
		{
			count++;
			while (src[index] == c)
				index++;
		}
		index++;
	}
	return (count);
}
static char	*ft_strncpy(char *dest, const char *src, char c)
{
	int	index;

	index = 0;
	while (src[index] != '\0' && src[index] != c)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*allocate_word(int count)
{
	char	*word;

	word = (char *)malloc((count + 1) * sizeof(char));
	if (!word)
		return (NULL);
	return (word);
}
int	ft_allocate(char **arr, int index, int count)
{
	int	t;

	t = 0;
	arr[index] = (char *)malloc((count + 1) * sizeof(char));
	if (!arr[index])
	{
		while (arr[t])
		{
			free(arr[t]);
			t++;
		}
		free(arr);
		return (1);
	}
	return (0);
}
char	**ft_split(char const *s, char c)
{
	int		count;
	char	**arr;
	int		index;

	count = count_words(s, c);
	arr = (char **)malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	index = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		count = word_length((char *)s, c);
		if (count)
		{
			if (ft_allocate(arr, index, count))
				return (NULL);
			ft_strncpy(arr[index], s, c);
			index++;
		}
		s += count;
	}
	arr[index] = (NULL);
	return (arr);
}
