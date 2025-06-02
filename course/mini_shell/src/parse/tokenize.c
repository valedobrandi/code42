#include "libft.h"
#include "../../include/minishell.h"
#include "parse_def.h"
#include <stdlib.h>

void	free_token_list(t_token_list *token_list)
{
	int	i;

	i = 0;
	if (!token_list)
		return ;
	while (i < token_list->size)
	{
		free(token_list->tokens[i].value);
		i++;
	}
	free(token_list->tokens);
	free(token_list);
}

static t_token_type	get_token_type(char *str)
{
	if (!str || str[0] == '\0')
		return (TOKEN_WORD);
	if (str[0] == IN && str[1] == IN)
		return (TOKEN_HERE_DOC);
	else if (str[0] == OUT && str[1] == OUT)
		return (TOKEN_REDIRECT_APPEND);
	else if (str[0] == IN)
		return (TOKEN_REDIRECT_IN);
	else if (str[0] == OUT)
		return (TOKEN_REDIRECT_OUT);
	else if (str[0] == PIPE)
		return (TOKEN_PIPE);
	else if (str[0] == DOUBLE_QUOTE && str[1] == TOKEN_DOLLAR)
		return (TOKEN_DOLLAR);
	else
		return (TOKEN_WORD);
}
static int	init_token_list(int length, char **strs, t_token_list *token_list)
{
	int	i;

	i = 0;
	while (i < length)
	{
		token_list->tokens[i].type = get_token_type(strs[i]);
		if (token_list->tokens[i].type == TOKEN_WORD)
			token_list->tokens[i].value = ft_strdup(strs[i]);
		else
			token_list->tokens[i].value = NULL;
		if (token_list->tokens[i].type == TOKEN_WORD
			&& token_list->tokens[i].value == NULL)
		{
			free_token_list(token_list);
			return (1);
		}
		token_list->size++;
		i++;
	}
	return (0);
}
t_token_list	*build_tokens(char **strs)
{
	t_token_list	*token_list;
	int				length;

	length = 0;
	while (strs[length])
		length++;
	token_list = malloc(sizeof(t_token_list));
	if (token_list == NULL)
		return (NULL);
	ft_memset(token_list, 0, sizeof(t_token_list));
	token_list->tokens = malloc(sizeof(t_token) * length);
	if (token_list->tokens == NULL)
		return (free(token_list), NULL);
	if (init_token_list(length, strs, token_list))
		return (NULL);
	return (token_list);
}
