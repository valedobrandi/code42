/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:39:05 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/02 11:55:50 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

int	g_data = 0;

int	main(void)
{
	t_token_list	*token_list;
	t_pipeline		*pipeline;
	char			*prompt;
	char			**strs;

	init_signal();
	while (1)
	{
		prompt = readline("minishell% ");
		if (prompt && *prompt)
			add_history(prompt);
		else if (prompt == NULL)
			return (0);
		prompt = ft_strtrim(prompt, " ");
		if (prompt == NULL)
			return (1);
		if (ft_strcmp(prompt, "") != 0)
		{
			strs = parse_prompt(prompt);
			free(prompt);
			if (strs != NULL)
			{
				token_list = build_tokens(strs);
				if (token_list != NULL)
				{
					free(strs);
					if (token_validation(token_list) == 0)
					{
						pipeline = build_pipeline(token_list);
						if (pipeline != NULL)
							execute_command(pipeline);
					}
				}
			}
		}
		else
			print_prompt(NULL, 1);
	}
	return (0);
}
