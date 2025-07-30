/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:35:40 by bde-albu          #+#    #+#             */
/*   Updated: 2025/05/20 09:10:51 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>

volatile sig_atomic_t	g_wait = 0;

void	wait_handle(int signum)
{
	(void)signum;
	g_wait = 1;
}

void	send_byte(pid_t pid_client, char c)
{
	int	bit_index;
	int	bit;

	bit_index = 7;
	while (bit_index >= 0)
	{
		g_wait = 0;
		bit = (c >> bit_index) & 1;
		if (bit == 0)
		{
			if (kill(pid_client, SIGUSR1) == -1)
				return (ft_putendl_fd("Failed to send signal", 2));
		}
		else
		{
			if (kill(pid_client, SIGUSR2) == -1)
				return (ft_putendl_fd("Failed to send signal", 2));
		}
		usleep(100);
		while (!g_wait)
			pause();
		bit_index--;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid_client;
	struct sigaction	sa;

	if (argc != 3)
		return (ft_putendl_fd("Usage: ./client [PID] [MESSAGE]", 2), 1);
	pid_client = ft_atoi(argv[1]);
	if (pid_client < 0)
		return (ft_putendl_fd("Invalid PID.", 2), 1);
	sa.sa_handler = &wait_handle;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	while (*argv[2])
		send_byte(pid_client, *argv[2]++);
	send_byte(pid_client, '\0');
	return (0);
}
