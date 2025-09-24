/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echoctl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:44:17 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/18 15:44:18 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <unistd.h>

void	disable_echoctl(void)
{
	struct termios	term;

	tcgetattr(STDERR_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void	enable_echoctl(void)
{
	struct termios	term;

	tcgetattr(STDERR_FILENO, &term);
	term.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
