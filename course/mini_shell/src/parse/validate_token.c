#include "minishell.h"
#include "parse_def.h"

int is_redirection(t_token_type type)
{
    return (type == TOKEN_REDIRECT_IN || type == TOKEN_REDIRECT_OUT ||
            type == TOKEN_REDIRECT_APPEND || type == TOKEN_HERE_DOC);
}

int token_validation(t_token_list *token_list)
{
    int current_token;
    int i;

    i = 0;
    while (i < token_list->size)
    {
        current_token = token_list->tokens[i].type;
        if (current_token == TOKEN_PIPE)
        {
            if (i == 0 || i == token_list->size - 1)
                return (print_prompt("Error", 2), 1);
            if (token_list->tokens[i - 1].type == TOKEN_PIPE ||
                token_list->tokens[i + 1].type == TOKEN_PIPE)
                return (print_prompt("Error", 2), 1);
        }
        if (is_redirection(current_token))
        {
            if (i == token_list->size - 1)
                return (print_prompt("Error", 2), 1);
            if (token_list->tokens[i - 1].type != TOKEN_WORD)
                return (print_prompt("Error", 2), 1);
        }
        i++;
    }
    return (0);
}
