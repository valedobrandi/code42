#include <unistd.h>
#include "libft.h"

int builtin_pwd()
{
    char *cwd;
    char buff[1024];

    cwd = getcwd(buff, 1024);
    if (cwd != NULL)
        ft_putendl_fd(cwd, 1);
    return (0);
}