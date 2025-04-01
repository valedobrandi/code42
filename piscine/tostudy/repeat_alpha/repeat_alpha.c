/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:22:03 by bde-albu          #+#    #+#             */
/*   Updated: 2025/02/20 11:28:59 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_string(char is_upper, char str)
{
	int	multiplier;
	int	index;

	index = 0;
	multiplier = str - is_upper;
	while (index <= multiplier)
	{
		write(1, &str, 1);
		index++;
	}
}

int	main(int argc, char **argv)
{
	int	index;
	(void)argc;

	
	if (argc == 2 && argv[1][0] != '\0') 
	{
		index = 0;
		while (argv[1][index] != '\0')
		{
			if (argv[1][index] >= 'a' && argv[1][index] <= 'z')
				print_string('a', argv[1][index]);
			if (argv[1][index] >= 'A' && argv[1][index] <= 'Z')
				print_string('A', argv[1][index]);
			index++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
