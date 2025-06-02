#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "minishell.h"
#include <stdlib.h>
#include <string.h>

// Helper: create token
t_token make_token(t_token_type type, const char *value) {
    t_token token;
    token.type = type;
    token.value = strdup(value);
    return token;
}

// Helper: build token list
t_token_list *make_token_list(t_token *tokens, int size) {
    t_token_list *list = malloc(sizeof(t_token_list));
    list->tokens = tokens;
    list->size = size;
    return list;
}

// Helper: free pipeline
void free_pipeline(t_pipeline *pipeline) {
    if (!pipeline) return;
    for (int i = 0; i < pipeline->cmd_count; i++) {
        t_command *cmd = &pipeline->commands[i];
        free(cmd->cmd);
        for (int j = 0; cmd->args && cmd->args[j]; j++)
            free(cmd->args[j]);
        free(cmd->args);
        free(cmd->input_file);
        free(cmd->output_file);
    }
    free(pipeline->commands);
    free(pipeline);
}

// Test 1: basic command
Test(build_pipeline, basic_command) {
    t_token tokens[] = {
        make_token(TOKEN_WORD, "ls"),
        make_token(TOKEN_WORD, "-la"),
    };

    t_token_list *list = make_token_list(tokens, 2);
    t_pipeline *pipeline = build_pipeline(list);

    cr_assert_not_null(pipeline);
    cr_assert_eq(pipeline->cmd_count, 1);

    t_command *cmd = &pipeline->commands[0];
    cr_assert_str_eq(cmd->cmd, "ls");
    cr_assert_str_eq(cmd->args[0], "ls");
    cr_assert_str_eq(cmd->args[1], "-la");
    cr_assert_null(cmd->args[2]);

    free_pipeline(pipeline);
    free(list->tokens[0].value);
    free(list->tokens[1].value);
    free(list);
}

// Test 2: command with redirection
Test(build_pipeline, redirections) {
    t_token tokens[] = {
        make_token(TOKEN_WORD, "cat"),
        make_token(TOKEN_REDIRECT_IN, "<"),
        make_token(TOKEN_WORD, "input.txt"),
        make_token(TOKEN_REDIRECT_OUT, ">"),
        make_token(TOKEN_WORD, "output.txt"),
    };

    t_token_list *list = make_token_list(tokens, 5);
    t_pipeline *pipeline = build_pipeline(list);

    cr_assert_not_null(pipeline);
    t_command *cmd = &pipeline->commands[0];

    cr_assert_str_eq(cmd->cmd, "cat");
    cr_assert_str_eq(cmd->input_file, "input.txt");
    cr_assert_str_eq(cmd->output_file, "output.txt");
    cr_assert_eq(cmd->append_mode, 0);

    free_pipeline(pipeline);
    for (int i = 0; i < 5; i++) free(tokens[i].value);
    free(list);
}

// Test 3: pipeline command (cmd1 | cmd2)
Test(build_pipeline, with_pipe) {
    t_token tokens[] = {
        make_token(TOKEN_WORD, "echo"),
        make_token(TOKEN_WORD, "hello"),
        make_token(TOKEN_PIPE, "|"),
        make_token(TOKEN_WORD, "grep"),
        make_token(TOKEN_WORD, "h"),
    };

    t_token_list *list = make_token_list(tokens, 5);
    t_pipeline *pipeline = build_pipeline(list);

    cr_assert_not_null(pipeline);
    cr_assert_eq(pipeline->cmd_count, 2);

    t_command *cmd1 = &pipeline->commands[0];
    cr_assert_str_eq(cmd1->cmd, "echo");
    cr_assert_str_eq(cmd1->args[1], "hello");

    t_command *cmd2 = &pipeline->commands[1];
    cr_assert_str_eq(cmd2->cmd, "grep");
    cr_assert_str_eq(cmd2->args[1], "h");

    free_pipeline(pipeline);
    for (int i = 0; i < 5; i++) free(tokens[i].value);
    free(list);
}
