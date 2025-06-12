/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:34:27 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/12 11:13:41 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>

extern int				g_data;

typedef struct s_list	t_list;

typedef enum e_redir_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC
}						t_redir_type;

typedef struct s_redir
{
	t_redir_type		type;
	char				*file;
}						t_redir;

typedef struct s_init_env
{
	int					k_len;
	char				*sing;
	char				*key;
	char				*value;
	bool				export;
}						t_init_env;

typedef struct s_get_token
{
	char				*str;
	char				*tmp;
	int					size;
	int					i;
	int					n;
}						t_get_token;

typedef enum s_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_REDIRECT_APPEND,
	TOKEN_HEREDOC,
}						t_token_type;

typedef struct s_token
{
	char				*value;
	t_token_type		type;
}						t_token;

typedef struct s_token_list
{
	t_token				*tokens;
	int					size;
}						t_token_list;

typedef struct s_command
{
	char				*cmd;
	char				**args;
	t_redir				*redirs[25];
}						t_command;

typedef struct s_pipeline
{
	t_command			*cmd;
	int					cmd_count;
}						t_pipeline;

int						init_signal(void);

char					**parse_prompt(char *prompt);

/* helper */

char					**linkedList_to_arr(t_list *env_list);

void					update(t_init_env *new_env, t_init_env **list_env);

t_init_env				*find_varible(t_list **env_list, char *arg);

int						update_env_list(char *arg, t_list **env_list);

t_list					*copy_env_list(t_list *env_list);

t_init_env				allocate_env(char *envp, bool export);

void					print_alphabetic_order(t_list *env_list,
							void (*print)(t_list *env_list, char c));

void					print(void *content);

void					free_env(void *content);

void					free_env_list(t_list **env_list);

void					free_array(char **strs);

void					free_pipeline(t_pipeline *pipeline);

void					free_token_list(t_token_list *token_list);

int						quote_error(char *prompt);

int						is_redirection(t_token_type type);

t_token_list			*build_tokens(char **strs);

t_pipeline				*build_pipeline(t_token_list *token_list);

void					print_prompt(char *message, int std);

void					print_newnl_prompt(void);

void					print_new_prompt(void);

/* builtin */

int						builtin_pwd(void);

int						builtin_cd(char **args);

int						builtin_echo(char **args);

int						builtin_export(char **args, t_list *env_list);

int						builtin_unset(char **args, t_list **env_list);

int						builtin_env(char **args, t_list **env_list);

/* execute */

int						execute_command(t_pipeline *pipeline,
							t_list **env_list);

/* env */
char					*get_variable(char *env);

int						ft_env_length(char *env);

t_list					*init_env(char **envp);

/* token */
void					single_quote(t_get_token *t);

int						double_quote(t_get_token *t);

int						no_quote(t_get_token *t);

char					*append(t_get_token *t);

int						token_validation(t_token_list *token_list);

int						apply_redirections(t_redir **redir, int fd);

/* redir */
char					**convert_env_list_to_envp(t_list *env_list);

char					*get_path(char *cmd, char **envp);

void					free_split(char **array);

#endif