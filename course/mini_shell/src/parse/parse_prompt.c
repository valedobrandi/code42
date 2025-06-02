#include "libft.h"
#include "minishell.h"
#include "parse_def.h"
#include <stdlib.h>

static int	get_operator(char *prompt, int *i, int *p, char **strs)
{
	int length;

	length = 1;
	if (prompt[*i + 1] == IN || prompt[*i + 1] == OUT)
		length++;
	strs[*p] = malloc((length + 1) * sizeof(char));
	if (strs[*p] == NULL)
		return (1);
	ft_strlcpy(strs[*p], &prompt[*i], length + 1);
	*i += length;
	(*p)++;
	return (0);
}

static int	get_word_length(char *prompt)
{
	int	double_quote;
	int	single_quote;
	int	i;

	double_quote = 0;
	single_quote = 0;
	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == SINGLE_QUOTE && double_quote == 0)
			single_quote = !single_quote;
		else if (prompt[i] == DOUBLE_QUOTE && single_quote == 0)
			double_quote = !double_quote;
		else if (single_quote == 0 && double_quote == 0)
			if (prompt[i] == IN || prompt[i] == OUT || prompt[i] == SPACE
				|| prompt[i] == TAB)
				break ;
		i++;
	}
	return (i);
}
static int	get_word(char *prompt, int *i, int *p, char **strs)
{
	int	length;

	length = get_word_length(&prompt[*i]);
	strs[*p] = malloc((length + 1) * sizeof(char));
	if (strs[*p] == NULL)
		return (1);
	ft_strlcpy(strs[*p], &prompt[*i], length + 1);
	*i += length;
	(*p)++;
	return (0);
}

static char	**parse(char *prompt, char **strs)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (prompt[i])
	{
		while (prompt[i] == SPACE || prompt[i] == TAB)
			i++;
		if (prompt[i] == '\0')
			break ;
		if (prompt[i] == IN || prompt[i] == OUT)
		{
			if (get_operator(prompt, &i, &p, strs))
				return (free_array(strs), NULL);
		}
		else
		{
			if (get_word(prompt, &i, &p, strs))
				return (free_array(strs), NULL);
		}
	}
	strs[p] = NULL;
	return (strs);
}

char	**parse_prompt(char *prompt)
{
	char	**strs;

	if (quote_error(prompt) != 0)
		return (print_prompt("> error", 2), NULL);
	strs = malloc(sizeof(char *) * 1024);
	if (!strs)
		return (NULL);
	if (parse(prompt, strs) == NULL)
		return (NULL);
	return (strs);
}
