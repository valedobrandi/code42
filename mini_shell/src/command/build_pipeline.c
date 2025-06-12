#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

int	count_pipe(t_token_list *token_list)
{
	int	count;
	int	index;

	index = 0;
	count = 0;
	while (index < token_list->size)
	{
		if (token_list->tokens[index].type == TOKEN_PIPE)
			count++;
		index++;
	}
	return (count);
}

int	count_words(t_token_list *token_list)
{
	int	count;
	int	index;

	index = 0;
	count = 0;
	while (index < token_list->size
		&& token_list->tokens[index].type != TOKEN_PIPE)
	{
		if (token_list->tokens[index].type == TOKEN_WORD)
			count++;
		index++;
	}
	return (count);
}

t_pipeline	*init_pipeline(void)
{
	t_pipeline	*pipeline;

	pipeline = malloc(sizeof(t_pipeline));
	if (pipeline == NULL)
		return (NULL);
	ft_memset(pipeline, 0, sizeof(t_pipeline));
	return (pipeline);
}

int	init_commands(t_pipeline *pipeline, int size)
{
	pipeline->cmd = malloc(sizeof(t_command) * size);
	if (pipeline->cmd == NULL)
		return (1);
	ft_memset(pipeline->cmd, 0, sizeof(t_command));
	pipeline->cmd_count = size;
	return (0);
}

t_redir_type	get_type(t_token_type token)
{
	if (token == TOKEN_REDIRECT_IN)
		return (REDIR_IN);
	else if (token == TOKEN_REDIRECT_OUT)
		return (REDIR_OUT);
	else if (token == TOKEN_REDIRECT_APPEND)
		return (REDIR_APPEND);
	else
		return (REDIR_HEREDOC);
}

int	build_commmand(t_token_list *token_list, t_command *cmd, int token_size,
		int *index)
{
	int		argc;
	int		redir_count;
	t_token	*token;

	argc = 0;
	redir_count = 0;
	cmd->args = malloc(sizeof(char *) * (count_words(token_list) + 1));
	if (cmd->args == NULL)
		return (1);
	while (*index < token_size && token_list->tokens[*index].type != TOKEN_PIPE)
	{
		token = token_list->tokens;
		if (is_redirection(token[*index].type))
		{
			cmd->redirs[redir_count] = malloc(sizeof(t_redir));
			if (!cmd->redirs[redir_count])
				return (1);
			cmd->redirs[redir_count]->file = ft_strdup(token[*index + 1].value);
			if (!cmd->redirs[redir_count]->file)
				return (1);
			cmd->redirs[redir_count]->type = get_type(token[*index].type);
			*index += 2;
			redir_count++;
		}
		else if (token[*index].type == TOKEN_WORD)
		{
			if (!cmd->cmd)
				cmd->cmd = ft_strdup(token[*index].value);
			cmd->args[argc++] = ft_strdup(token[*index].value);
		}
		(*index)++;
	}
	cmd->args[argc] = NULL;
	cmd->redirs[redir_count] = NULL;
	if (token_list->tokens[*index].type == TOKEN_PIPE)
		(*index)++;
	return (0);
}
t_pipeline	*build_pipeline(t_token_list *token_list)
{
	t_pipeline	*pipeline;
	int			command_count;
	int			cmd_index;
	int			index;

	pipeline = init_pipeline();
	if (pipeline == NULL)
		return (NULL);
	command_count = count_pipe(token_list) + 1;
	if (init_commands(pipeline, command_count))
		return (NULL);
	index = 0;
	cmd_index = 0;
	while (index < token_list->size && cmd_index < command_count)
	{
		if (build_commmand(token_list, &pipeline->cmd[cmd_index],
				token_list->size, &index))
			return (NULL);
		cmd_index++;
	}
	return (pipeline);
}
