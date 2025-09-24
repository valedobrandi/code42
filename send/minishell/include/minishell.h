/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:34:27 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/23 09:21:52 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <sys/types.h>

extern int				g_sigint_received;

typedef struct s_list	t_list;

typedef struct s_exec_pipe
{
	int					i;
	pid_t				last_pid;
	int					pipe_fd[2];
	int					prev_fd;
	int					exit_return;
	pid_t				pid;

}						t_exec_pipe;

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
	char				sing;
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
	t_command			*cmds;
	int					cmd_count;
}						t_pipeline;

/* parse */

char					**parse_prompt(char *prompt, int *exit_code);

char					**parse(char *prompt, char **strs, int *p);

int						pipe_handle(char **strs, int *p);

int						validate_parse(char **strs, int *exit_code);

/* signal */
int						init_signal(void);

void					disable_echoctl(void);

void					enable_echoctl(void);

/* helper */

char					*expand_env(char *arg, t_list **env_list);

char					**linkedlist_to_arr(t_list *env_list);

int						is_path(char *path);

void					update_env(t_init_env *new_env, t_init_env *list_env);

t_init_env				*find_variable(t_list *env_list, char *arg);

int						update_env_list(char *arg, t_list **env_list);

t_list					*copy_env_list(t_list *env_list);

t_init_env				allocate_env(char *envp, bool export);

void					print_alphabetic_order(t_list *env_list,
							void (*print)(t_list *env_list, char c));

void					print_env(void *content, int type);

void					free_env(void *content);

void					free_env_list(t_list **env_list);

void					free_array(char **strs);

void					free_pipeline(t_pipeline *pipeline);

void					free_token_list(t_token_list *token_list);

int						quote_error(char *prompt, int *exit_code);

int						is_redirection(t_token_type type);

t_token_list			*build_tokens(char **strs, t_list *envp);

t_pipeline				*build_pipeline(t_token_list *token_list);

void					print_prompt(char *message, int std);

/* builtin */

int						builtin_pwd(void);

int						builtin_cd(char **args, t_list **env_list);

int						builtin_echo(char **args);

int						builtin_exit(char **args, int is_child_process);

int						builtin_export(char **args, t_list **env_list);

int						builtin_unset(char **args, t_list **env_list);

int						builtin_env(char **args, t_list **env_list);

/* execute */

int						execute_command(t_pipeline *pipeline, t_list **env_list,
							int *exit_code);

void					execute_execve(char **args, char *cmd, char *bin_path,
							char **env);

void					execute_redirects(t_command cmd, char **env);

void					validate_path(char *cmd, char *bin_path, char **env);

/* env */
char					*get_variable(char *env, t_list *env_list);

int						env_length(char *input);

t_list					*init_env(char **envp);

int						expand_system_return(int sys, char **args, char **cmd);

/* token */
void					single_quote(t_get_token *t);

int						double_quote(t_get_token *t, t_list *env_list);

int						no_quote(t_get_token *t, t_list *env_list);

char					*append(t_get_token *t, t_list *env_list);

int						token_validation(t_token_list *token_list,
							int *exit_code);

int						is_operator_valid(t_token_type type, char *value);

int						is_valid_redirection_target(t_token_list *list, int i);

int						validate_directions(int current_token,
							t_token_list *token_list, int i);

int						apply_redirections(t_redir **redir);

/* redir */
char					**convert_env_list_to_envp(t_list *env_list);

char					*get_path(char *cmd, char **envp);

void					free_split(char **array);

int						apply_redirections(t_redir **redirs);

int						redirect_input(const char *filename);

int						redirect_output(const char *filename);

int						redirect_output_append(const char *filename);

/* exec_pipeline */
int						exec_pipeline(t_pipeline *pipeline, t_list **env_list,
							int *exit_code, char **env);

int						exec_builtin(char *cmd, char **args, t_list **env_list);

int						is_builtin(char *cmd);

void					wait_children_process_exit(pid_t last_pid,
							int *exit_code);

void					child_pipeline_process(t_pipeline *pipeline,
							t_exec_pipe *t, t_list **envp_list, char **env);

/* exec_command*/

int						exec_command(t_pipeline *pipeline, t_list **envp_list,
							int *exit_code, char **env);

int						builtins_cmd(t_pipeline *pipeline, t_list **envp_list,
							int *exit_code);

void					exit_cleanup(char **env, char *bin_path, int code);

/* pipeline */

t_pipeline				*init_pipeline(void);

int						init_commands(t_pipeline *pipeline, int size);

int						build_commmand(t_token_list *token_list, t_command *cmd,
							int token_size, int *index);

int						count_pipe(t_token_list *token_list);

t_redir_type			get_type(t_token_type token);

#endif