#include "cub3d.h"
#include "libft.h"

static int	is_valid(int count, int start, char *rbg)
{
	if (count > 0 && count < 4)
		if (ft_atoi(rbg + start) <= 255 && ft_atoi(rbg + start) >= 0)
			return (1);
	return (0);
}

static int	validate_rbg_format(char *rbg, int *i, char stop)
{
	int	count;
	int	start;

	count = 0;
	start = *i;
	while (rbg[*i] && rbg[*i] != stop)
	{
		while (rbg[*i] == ' ' || rbg[*i] == '\t' || rbg[*i] == '\r')
			(*i)++;
		if (!ft_isdigit(rbg[*i]))
			return (0);
		while (ft_isdigit(rbg[*i]))
		{
			count++;
			(*i)++;
		}
		while (rbg[*i] == ' ' || rbg[*i] == '\t' || rbg[*i] == '\r')
			(*i)++;
	}
	return (is_valid(count, start, rbg));
}

static int	parse_rgb(char *type, char *rbg)
{
	int	i;

	i = 0;
	if (!ft_strcmp(type, "F") || !ft_strcmp(type, "C"))
	{
		if (!validate_rbg_format(rbg, &i, ','))
			return (1);
		i++;
		if (!validate_rbg_format(rbg, &i, ','))
			return (1);
		i++;
		if (!validate_rbg_format(rbg, &i, '\0'))
			return (1);
		return (0);
	}
	return (0);
}
static int	save(t_settings *st, char *type, char *rbg)
{
	char **temp;

	if (!ft_strcmp(type, "F"))
	{
		temp = ft_split(rbg, ',');
		if (!temp)
        	return (1);
		st->rbg_f[0] = ft_atoi(temp[0]);
		st->rbg_f[1] = ft_atoi(temp[1]);
		st->rbg_f[2] = ft_atoi(temp[2]);
		free_array(temp);
	}
	if (!ft_strcmp(type, "C"))
	{
		temp = ft_split(rbg, ',');
		if (!temp)
        	return (1);
		st->rbg_c[0] = ft_atoi(temp[0]);
		st->rbg_c[1] = ft_atoi(temp[1]);
		st->rbg_c[2] = ft_atoi(temp[2]);
		free_array(temp);
	}
	return (0);
}

int	validate_rgb(t_list *lst, t_settings *st)
{
	t_entries	*content;

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
		if (save(st, content->type, content->path))
			return (1);
		lst = lst->next;
	}
	return (0);
}
