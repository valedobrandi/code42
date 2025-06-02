/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:34:27 by bde-albu          #+#    #+#             */
/*   Updated: 2025/06/02 10:33:23 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stddef.h>

extern int g_data;

typedef enum s_token_type
{
    TOKEN_WORD,
    TOKEN_DOLLAR,
    TOKEN_PIPE,
    TOKEN_REDIRECT_IN,
    TOKEN_REDIRECT_OUT,
    TOKEN_REDIRECT_APPEND,
    TOKEN_HERE_DOC
} t_token_type;

typedef struct s_token
{
    char *value;
    t_token_type type;
} t_token;

typedef struct s_token_list
{
    t_token *tokens;
    int size;
} t_token_list;

typedef struct s_command
{
    char *cmd;
    char **args;
    char *input_file;
    char *output_file;
    int append_mode;
} t_command;

typedef struct s_pipeline
{
    t_command *commands;
    int cmd_count;
} t_pipeline;

int init_signal();

char **parse_prompt(char *prompt);

void free_array(char **strs);

int quote_error(char *prompt);

int token_validation(t_token_list *token_list);

int is_redirection(t_token_type type);

t_token_list *build_tokens(char **strs);

void free_token_list(t_token_list *token_list);

t_pipeline *build_pipeline(t_token_list *token_list);

void print_prompt(char *message, int std);

void print_newnl_prompt();

void print_new_prompt();

int builtin_pwd();

int builtin_cd(char **args);

int builtin_echo(char **args);

void execute_command(t_pipeline *pipeline);

#endif