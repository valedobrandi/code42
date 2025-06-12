/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:39:05 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/11 09:50:10 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

int	g_data = 0;

int	main(int ac, char **av, char **envp)
{
	t_list			*env_list;
	t_token_list	*token_list;
	t_pipeline		*pipeline;
	char			*temp;
	char			*prompt;
	char			**strs;

	(void)ac;
	(void)av;

	init_signal();

	env_list = init_env(envp);
	if (env_list == NULL)
		return (ft_putstr_fd("fail to laod environament list", 2), 1);

	while (1)
	{
		pipeline = NULL; // ✅ IMPORTANT
		temp = readline("minishell% ");
		if (temp && *temp)
			add_history(temp);
		else if (temp == NULL)
		{
			ft_putendl_fd("exit", 1);
			break;
		}
		prompt = ft_strtrim(temp, " ");
		free(temp); // ✅ évite leak
		if (prompt == NULL)
			return (1);
		if (quote_error(prompt))
			print_prompt("> error", 2);
		if (ft_strcmp(prompt, "") != 0)
		{
			strs = parse_prompt(prompt);
			free(prompt);
			if (strs != NULL)
			{
				token_list = build_tokens(strs);
				free_split(strs); // ✅ évite leak
				if (token_list != NULL)
				{
					if (token_validation(token_list) == 0)
					{
						pipeline = build_pipeline(token_list);
						free_token_list(token_list);
						token_list = NULL;
						if (pipeline != NULL)
							if (execute_command(pipeline, &env_list) == 1)
								break;
					}
					if (token_list)
						free_token_list(token_list);
					free_pipeline(pipeline);
				}
			}
		}
		else
			print_prompt(NULL, 1);

	}
	if (pipeline)
		free_pipeline(pipeline);
	free_env_list(&env_list);
	rl_clear_history();
	return (0);
}
