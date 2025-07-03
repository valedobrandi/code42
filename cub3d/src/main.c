#include "cub3d.h"
#include "libft.h"
#include <stdlib.h>

int allocate_schema(t_map **schema)
{
    *schema = malloc(sizeof(t_map));
    if (!*schema)
        return (1);
    (*schema)->map = malloc(sizeof(t_map_line) * BUFFER);
    if (!(*schema)->map)
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    (void)ac;
    t_list *rgb_texture;
    t_map *schema;
    t_player player;

    ft_memset(&player, -1, sizeof(t_player));
    rgb_texture = NULL;
    allocate_schema(&schema);
    read_file(av[1], &rgb_texture, schema);
    validate_rgb(rgb_texture);
    validate_schema(schema, &player);
    ft_lstclear(&rgb_texture, free_entries);
    free_schema(schema);
    return (0);
}