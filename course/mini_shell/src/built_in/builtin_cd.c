#include <unistd.h>
#include "libft.h"

int builtin_cd(char **args)
{
    if (chdir(args[1]) == 0)
        return (0);
    return (1);
}