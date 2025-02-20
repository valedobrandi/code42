/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:00:16 by bde-albu          #+#    #+#             */
/*   Updated: 2025/02/19 17:11:15 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	swap(char **arr, int index)
{
	char	*temp;

	printf("Swap %s - ", arr[index]);
	printf("%s\n", arr[index + 1]);
	temp = arr[index];
	arr[index] = arr[index + 1];
	arr[index + 1] = temp;
}

void	buble_sort(char **arr, int size)
{
	int	index;
	int	length;
	int	swapped;

	index = 0;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		while (index < size - 1)
		{
			length = 0;
			if (arr[index][0] > arr[index + 1][0])
			{
				swap(arr, index);
				swapped = 1;
			}
			else
			{
				while (arr[index][length] == arr[index + 1][length])
					length++;
				if (arr[index][length] > arr[index + 1][length])
				{
					swap(arr, index);
					swapped = 1;
				}
			}
			index++;
		}
	}
}
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	index;

	buble_sort(argv + 1, argc - 1);
	for (index = 1; index < argc; index++)
		printf("%s\n", argv[index]);
	return (0);
}
