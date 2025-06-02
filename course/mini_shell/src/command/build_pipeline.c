#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

int count_token_type(t_token_list *token_list, t_token_type type)
{
    int count;
    int index;

    index = 0;
    count = 0;
    while (index < token_list->size)
    {
        if (token_list->tokens[index].type == type)
            count++;
        index++;
    }
    return (count);
}

t_pipeline *init_pipeline()
{
    t_pipeline *pipeline;

    pipeline = malloc(sizeof(t_pipeline));
    if (pipeline == NULL)
        return (NULL);
    ft_memset(pipeline, 0, sizeof(t_pipeline));
    return (pipeline);
}

int init_commands(t_pipeline *pipeline, t_token_list *token_list, int size)
{
    pipeline->commands = malloc(sizeof(t_command) * size);
    if (pipeline->commands == NULL)
        return (free_token_list(token_list), 1);
    ft_memset(pipeline->commands, 0, sizeof(t_command));
    pipeline->cmd_count = size;
    return (0);
}

int build_commmand(t_token_list *token_list, t_command *command, int token_size, int *i)
{
    int argc = 0;
    int cmd_args = 1;

    command->args = malloc(sizeof(char *) * (token_size + 1));
    if (command->args == NULL)
        return (-1);
    while (*i < token_size && token_list->tokens[*i].type != TOKEN_PIPE)
    {
        t_token token = token_list->tokens[*i];
        if (token.type == TOKEN_WORD && cmd_args)
        {
            if (!command->cmd)
                command->cmd = ft_strdup(token.value);
            command->args[argc++] = ft_strdup(token.value);
        }
        if (*i + 1 < token_size && is_redirection(token.type))
        {
            if (token.type == TOKEN_REDIRECT_IN)
                command->input_file = ft_strdup(token_list->tokens[*i + 1].value);
            else if (token.type == TOKEN_REDIRECT_OUT)
            {
                command->output_file = ft_strdup(token_list->tokens[*i + 1].value);
                command->append_mode = 0;
            }
            else if (token.type == TOKEN_REDIRECT_APPEND)
            {
                command->output_file = ft_strdup(token_list->tokens[*i + 1].value);
                command->append_mode = 1;
            }
            else if (token.type == TOKEN_HERE_DOC)
            {
                command->input_file = ft_strdup(token_list->tokens[*i + 1].value);
                command->append_mode = -1;
            }
            *i += 2;
            cmd_args = 0;
        }
        (*i)++;
    }
    command->args[argc] = NULL;
    return (1);
}
t_pipeline *build_pipeline(t_token_list *token_list)
{
    t_pipeline *pipeline;
    int command_count;
    int cmd_index;
    int i;

    pipeline = init_pipeline();
    if (pipeline == NULL)
        return (free_token_list(token_list), NULL);

    command_count = count_token_type(token_list, TOKEN_PIPE) + 1;
    if (init_commands(pipeline, token_list, command_count))
        return (NULL);

    i = 0;
    cmd_index = 0;
    while (i < token_list->size && cmd_index < command_count)
    {
        if (build_commmand(token_list, &pipeline->commands[cmd_index], token_list->size, &i) == -1)
            return (NULL);
        cmd_index++;
    }
    return (pipeline);
}
