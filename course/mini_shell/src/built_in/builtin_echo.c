#include "libft.h"
#include "minishell.h"

int builtin_echo(char **args)
{
    int i = 1;
    int newline = 1;

    if (args[i] && ft_strcmp(args[i], "-n") == 0)
    {
        newline = 0;
        i++;
    }
    while (args[i])
    {
        ft_putstr_fd(args[i], 1);
        if (args[i + 1])
            ft_putstr_fd(" ", 1);
        i++;
    }
    if (newline)
        ft_putendl_fd("", 1);
    return (0);
}