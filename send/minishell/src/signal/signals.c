/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:00:02 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/23 11:57:31 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_printf.h"
#include <readline/readline.h>
#include <signal.h>
#include <unistd.h>

int			g_sigint_received = 0;

static void	sigint_handler(int signum)
{
	if (signum == SIGINT)
	{
		if (g_sigint_received)
			write(1, "^C\n", 3);
		else
			write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		if (!g_sigint_received)
			rl_redisplay();
	}
	if (signum == SIGQUIT && g_sigint_received)
		ft_printf("^\\Quit (core dumped)\n");
}

int	init_signal(void)
{
	struct sigaction	sa;

	rl_catch_signals = 0;
	sa.sa_handler = sigint_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	return (0);
}
