#include "cub3d.h"
#include <stdlib.h>

void free_scheme(t_map *schema)
{
    int i;

    i = 0;
    if (!schema)
        return;
    while (i < schema->height)
    {
        free(schema->map[i].path);
        i++;
    }
    free(schema->map);
    free(schema);
    schema = NULL;
}