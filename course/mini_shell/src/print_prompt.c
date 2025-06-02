#include <readline/readline.h>
#include "libft.h"

void print_prompt(char *message, int std)
{
    if (message)
        ft_putendl_fd(message, std);
    rl_replace_line("", 0);
    rl_on_new_line();
    rl_redisplay();
}

void print_newnl_prompt()
{
    rl_replace_line("", 0);
    rl_on_new_line();
    rl_redisplay();
}

void print_new_prompt()
{
    rl_replace_line("", 0);
    rl_redisplay();
}

