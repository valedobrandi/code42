/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 08:16:27 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/11 16:08:40 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void free_pipeline(t_pipeline *pipeline) {
    if (!pipeline) return;
    for (int i = 0; i < pipeline->cmd_count; i++) {
        t_command *cmd = &pipeline->cmd[i];
        free(cmd->cmd);
        for (int j = 0; cmd->args && cmd->args[j]; j++)
            free(cmd->args[j]);
        free(cmd->args);
		for (int t = 0; cmd->redirs[t]; t++)
			free(cmd->redirs[t]->file);
    }
    free(pipeline->cmd);
    free(pipeline);
}
