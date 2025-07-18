/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:35:48 by bde-albu          #+#    #+#             */
/*   Updated: 2025/05/20 09:14:12 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int		g_data = 0;

void	sig_handler(int signum, siginfo_t *info, void *ucontext)
{
	unsigned char	received;
	int				bit_count;

	(void)ucontext;
	received = g_data & 0xFF;
	bit_count = (g_data >> 8);
	if (signum == SIGUSR1)
		received = (received << 1);
	else if (signum == SIGUSR2)
		received = (received << 1) | 1;
	bit_count++;
	g_data = (bit_count << 8) | received;
	if (kill(info->si_pid, SIGUSR1) == -1)
		return (ft_putendl_fd("Failed to send signal", 2));
	if (bit_count == 8)
	{
		if (received == '\0')
			write(1, "\n", 1);
		else
			write(1, &received, 1);
		g_data = 0;
	}
}

int	main(void)
{
	pid_t				pid_server;
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
	pid_server = getpid();
	ft_putnbr_fd(pid_server, 1);
	while (1)
		pause();
	return (0);
}
