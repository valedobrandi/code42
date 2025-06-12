#include "../../include/minishell.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

int builtin_cd(char **args)
{
	if (args[2] != NULL)
		return (print_prompt("cd: too many arguments", 2), 1);
	else if (args[1] == NULL)
		return (print_prompt("cd: missing argument", 2), 1);
    else if (chdir(args[1]) == 0)
        return (0);
	else
		perror("cd");
    return (1);
}