#include "cub3d.h"
#include "libft.h"

static int validate_rbg_format(char *RGB, int *i, char stop)
{
    int count;
    int start;

    count = 0;
    start = *i;
    while (RGB[*i] && RGB[*i] != stop)
    {
        while (RGB[*i] == ' ' || RGB[*i] == '\t' || RGB[*i] == '\r')
            (*i)++;
        if (!ft_isdigit(RGB[*i]))
            return (0);
        while (ft_isdigit(RGB[*i]))
        {
            count++;
            (*i)++;
        }
        while (RGB[*i] == ' ' || RGB[*i] == '\t' || RGB[*i] == '\r')
            (*i)++;
    }
    return (count > 0 && count < 4 && ft_atoi(RGB + start) <= 255 && ft_atoi(RGB + start) >= 0);
}

static int parse_rgb(char *type, char *RGB)
{
    int i;

    i = 0;
    if (!ft_strcmp(type, "F") || !ft_strcmp(type, "C"))
    {
        if (!validate_rbg_format(RGB, &i, ','))
            return (1);
        i++;
        if (!validate_rbg_format(RGB, &i, ','))
            return (1);
        i++;
        if (!validate_rbg_format(RGB, &i, '\0'))
            return (1);
        return (0);
    }
    return (0);
}

int validate_rgb(t_list *lst)
{
    t_entries *content;

    if (!lst)
        return (1);
    while (lst)
    {
        content = lst->content;
        if (content->type && content->path)
        {
            if (parse_rgb(content->type, content->path))
                return (1);
        }
        else
            return (1);
        lst = lst->next;
    }
    return (0);
}
