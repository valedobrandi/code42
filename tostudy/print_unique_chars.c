/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unique_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:59:43 by bde-albu          #+#    #+#             */
/*   Updated: 2025/02/19 12:52:15 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}
int	is_printable(char *str, char unique, int str_index)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == unique)
			return (0);
		index++;
	}
	return (1);
}

void	print_unique_caracters(char *arr, char *str, int *arr_index)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (is_printable(arr, str[index], index))
		{
			arr[*arr_index] = str[index];
			*arr_index = *arr_index + 1;
		}
		index++;
	}
}

int	main(int argn, char **argv)
{
	char arr[ft_strlen(argv[1]) + ft_strlen(argv[2]) + 1];
	int arr_index;
	(void)argn;

	arr_index = 0;
	print_unique_caracters(arr, argv[1], &arr_index);
	print_unique_caracters(arr, argv[2], &arr_index);
	arr[arr_index] = '\0';
	arr_index = 0;
	while (arr[arr_index] != '\0')
	{
		write(1, &arr[arr_index], 1);
		arr_index++;
	}
}