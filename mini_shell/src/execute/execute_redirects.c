/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redirects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:33:02 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/18 13:43:41 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	execute_redirects(t_command cmd, char **env)
{
	if (apply_redirections(cmd.redirs))
	{
		free_array(env);
		exit(1);
	}
}
