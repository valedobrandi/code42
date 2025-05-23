#include "push_swap.h"

static int	ft_strcpy(char *dst, char *src)
{
	while (*dst != '\0' && *src != '\0')
	{
		if (*dst != *src)
			return (1);
		dst++;
		src++;
	}
	if (*dst != *src)
		return (1);
	return (0);
}

void	print_command(char *next)
{
	static char	*prev = "";

	if ((ft_strcpy(prev, "sa") == 0 && ft_strcpy(next, "sb") == 0)
		|| ((ft_strcpy(prev, "sb") == 0 && ft_strcpy(next, "sa") == 0)))
		write(1, "ss\n", 3);
	else if ((ft_strcpy(prev, "ra") == 0 && ft_strcpy(next, "rb") == 0)
		|| ((ft_strcpy(prev, "rb") == 0 && ft_strcpy(next, "ra") == 0)))
		write(1, "rr\n", 3);
	else if ((ft_strcpy(prev, "rra") == 0 && ft_strcpy(next, "rrb") == 0)
		|| ((ft_strcpy(prev, "rrb") == 0 && ft_strcpy(next, "rra") == 0)))
		write(1, "rrr\n", 3);
	else if (ft_strcpy(next, "sa") == 0)
		write(1, "sa\n", 3);
	else if (ft_strcpy(next, "sb") == 0)
		write(1, "sb\n", 3);
	else if (ft_strcpy(next, "ra") == 0)
		write(1, "ra\n", 3);
	else if (ft_strcpy(next, "rb") == 0)
		write(1, "rb\n", 3);
	else if (ft_strcpy(next, "rra") == 0)
		write(1, "rra\n", 4);
	else if (ft_strcpy(next, "rrb") == 0)
		write(1, "rrb\n", 4);
	prev = next;
}
