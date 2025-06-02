#include "../include/minishell.h" 
#include <stdlib.h>
#include "libft.h"

char **dup_arr(char **src) {
    int count = 0;
    while (src[count])
        count++;

    char **dup = malloc(sizeof(char *) * (count + 1));
    if (!dup)
        return NULL;

    for (int i = 0; i < count; i++)
        dup[i] = ft_strdup(src[i]);

    dup[count] = NULL; // Null-terminate the array
    return dup;
}

void free_pipeline(t_pipeline *pipeline) {
    if (!pipeline) return;
    for (int i = 0; i < pipeline->cmd_count; i++) {
        t_command *cmd = &pipeline->commands[i];
        free(cmd->cmd);
        for (int j = 0; cmd->args && cmd->args[j]; j++)
            free(cmd->args[j]);
        free(cmd->args);
        free(cmd->input_file);
        free(cmd->output_file);
    }
    free(pipeline->commands);
    free(pipeline);
}