/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:39:05 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/20 14:54:48 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static t_list	*init_shell(char **envp, int *exit_code)
{
	init_signal();
	*exit_code = 0;
	return (init_env(envp));
}

static char	*handle_input_line(void)
{
	char	*line;
	char	*prompt;

	line = readline("minishell% ");
	if (!line)
	{
		ft_putendl_fd("exit", 1);
		rl_clear_history();
		return (NULL);
	}
	if (*line)
		add_history(line);
	prompt = ft_strtrim(line, " ");
	free(line);
	return (prompt);
}

static int	process_prompt(char *prompt, t_list **env_list, int *exit_code)
{
	char			**strs;
	t_token_list	*token_list;
	t_pipeline		*pipeline;
	int				res;

	if (quote_error(prompt, exit_code))
		return (0);
	if (ft_strcmp(prompt, "") == 0)
		return (print_prompt(NULL, 1), 0);
	strs = parse_prompt(prompt, exit_code);
	free(prompt);
	if (!strs)
		return (0);
	token_list = build_tokens(strs, *env_list);
	free_array(strs);
	if (!token_list)
		return (0);
	if (token_validation(token_list, exit_code) != 0)
		return (free_token_list(token_list), 0);
	pipeline = build_pipeline(token_list);
	free_token_list(token_list);
	if (!pipeline)
		return (0);
	res = execute_command(pipeline, env_list, exit_code);
	return (free_pipeline(pipeline), res);
}

int	main(int ac, char **av, char **envp)
{
	t_list	*env_list;
	char	*prompt;
	int		exit_code;

	(void)ac;
	(void)av;
	env_list = init_shell(envp, &exit_code);
	if (!env_list)
		return (ft_putstr_fd("fail to load environment list\n", 2), 1);
	while (1)
	{
		prompt = handle_input_line();
		if (!prompt)
			break ;
		if (process_prompt(prompt, &env_list, &exit_code))
			break ;
		g_sigint_received = 0;
	}
	free_env_list(&env_list);
	rl_clear_history();
	rl_deprep_terminal();
	return (exit_code);
}
