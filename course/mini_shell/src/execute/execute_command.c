#include "minishell.h"
#include "libft.h"

void execute_command(t_pipeline *pipeline)
{
    int i;

    i = 0;
    while (i < pipeline->cmd_count)
    {
        if (ft_strcmp(pipeline->commands[i].cmd, "echo") == 0)
            builtin_echo(pipeline->commands->args);
        else if (ft_strcmp(pipeline->commands[i].cmd, "pwd") == 0)
            builtin_pwd();
        else if (ft_strcmp(pipeline->commands[i].cmd, "cd") == 0)
            builtin_cd(pipeline->commands->args);
        i++;
    }
}