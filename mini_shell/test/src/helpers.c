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
