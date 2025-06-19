/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:42:45 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/18 15:42:47 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <readline/readline.h>

void	print_prompt(char *message, int std)
{
	if (message)
		ft_putendl_fd(message, std);
	rl_replace_line("", 0);
	rl_redisplay();
}
