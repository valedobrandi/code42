/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:08:44 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/18 13:11:30 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_redirections(t_command cmd, char **env)
{
	if (apply_redirections(cmd.redirs))
	{
		free_array(env);
		exit(1);
	}
}
