/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:27:25 by bde-albu          #+#    #+#             */
/*   Updated: 2025/02/11 12:15:53 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*table;
	int	length;
	int	index;

	if (min >= max)
		return (NULL);
	length = max - min;
	if (min < 0)
		length = max + (-min);
	table = (int *)malloc(length * sizeof(int));
	if (!table)
		return (NULL);
	index = 0;
	while (index < length)
	{
		table[index] = min;
		min = min + 1;
		index += 1;
	}
	return (table);
}
