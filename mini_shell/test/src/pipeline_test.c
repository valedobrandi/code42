#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "minishell.h"
#include <stdlib.h>
#include <string.h>

// Test 1: basic command
Test(create_pipeline, basic_command) {
    char *input = "ls | grep txt";
    char **strs = parse_prompt(input);
	t_token_list *tokens = build_tokens(strs);
	t_pipeline *pipeline = build_pipeline(tokens);

    cr_assert_not_null(pipeline);
    cr_assert_eq(pipeline->cmd_count, 2);

    t_pipeline *cmd = &pipeline->cmds[0];
    cr_assert_str_eq(cmd->cmds, "ls");
    cr_assert_str_eq(cmd->args[0], "ls");
    cr_assert_null(cmd->args[1]);

	t_pipeline *cmd2 = &pipeline->cmds[1];
    cr_assert_str_eq(cmd2->cmds, "grep");
    cr_assert_str_eq(cmd2->args[0], "grep");
    cr_assert_str_eq(cmd2->args[1], "txt");
    cr_assert_null(cmd2->args[2]);

	free_array(strs);
	free_token_list(tokens);
    free_pipeline(pipeline);
}

Test(create_pipeline, basic_command_operator) {
    char *input = "ls > a";
    char **strs = parse_prompt(input);
	t_token_list *tokens = build_tokens(strs);
	t_pipeline *pipeline = build_pipeline(tokens);

    cr_assert_not_null(pipeline);
    cr_assert_eq(pipeline->cmd_count, 1);

    t_pipeline *cmd = &pipeline->cmds[0];
    cr_assert_str_eq(cmd->cmds, "ls");
    cr_assert_str_eq(cmd->args[0], "ls");
	cr_assert_str_eq(cmd->redirs[0]->file, "a");
    cr_assert_null(cmd->args[1]);

	free_array(strs);
	free_token_list(tokens);
    free_pipeline(pipeline);
}

/* // Test 2: command with redirection
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
 */