/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:39:05 by bde-albu          #+#    #+#             */
/*   Updated: 2025/05/27 13:53:17 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include "../minishell.h"

int g_data = 0;

int	main(void)
{
	char *prompt;

	signal(SIGINT, sigint_handler);
	while (1)
	{
		prompt = readline("% ");
		if (prompt && *prompt)
			add_history(prompt);
		if (built_int_command(prompt) == 1)
			return (0);
		printf("%s\n", prompt);
	}

	return (0);
}