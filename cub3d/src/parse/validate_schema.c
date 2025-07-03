#include "cub3d.h"
#include "libft.h"

static int get_validate_player(char *pixel, int x, int y, t_player *player)
{
    if (pixel[x] == 'N' || pixel[x] == 'S' || pixel[x] == 'W' || pixel[x] == 'O')
    {
        if ((*player).cord_y != -1 || (*player).cord_x != -1)
            return (ft_putendl_fd("Error: too many players", 2), 1);
        (*player).cord_y = y;
        (*player).cord_x = x;
    }
    return (0);
}

static int validate_character(char *pixel, int x)
{
    if (pixel[x] != 'N' && pixel[x] != 'S' && pixel[x] != 'W' && pixel[x] != 'O' && pixel[x] != '1' && pixel[x] != '0' && !is_space(pixel[x]))
        return (ft_putendl_fd("Error: bad mapping character", 2), 1);
    return (0);
}

int validate_schema(t_map *schema, t_player *player)
{
    int y;
    int x;

    y = 0;
    while (y < schema->height)
    {
        x = 0;
        while (x < schema->map[y].length)
        {
            if (get_validate_player(schema->map[y].path, x, y, player) || validate_character(schema->map[y].path, x))
                return (1);
            x++;
        }
        y++;
    }
    if (player->cord_x == -1 || player->cord_y == -1)
        return (ft_putendl_fd("Error: no player", 2), 1);
    return (0);
}
