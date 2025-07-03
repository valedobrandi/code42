#include <stdlib.h>
#include "cub3d.h"

void free_entries(void *content)
{
    t_entries *t;

    t = content;
    if (t->path)
        free(t->path);
    if (t->type)
        free(t->type);
    free(t);
}