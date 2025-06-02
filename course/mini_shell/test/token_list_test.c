#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "minishell.h"

Test(build_tokens_suite, simple_command) {
    char *input = "echo hello";
	char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(tokens->size, 2);
    cr_assert_str_eq(tokens->tokens[0].value, "echo");
    cr_assert_eq(tokens->tokens[0].type, TOKEN_WORD);
    cr_assert_str_eq(tokens->tokens[1].value, "hello");
    cr_assert_eq(tokens->tokens[1].type, TOKEN_WORD);

    free_token_list(tokens);
}

Test(build_tokens_suite, pipe_command) {
    char *input = "ls | grep txt";
    char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(tokens->size, 4);
    cr_assert_eq(tokens->tokens[1].type, TOKEN_PIPE);
    cr_assert_str_eq(tokens->tokens[1].value, "|");

    free_token_list(tokens);
}

Test(build_tokens_suite, redirections) {
    char *input = "cat < input.txt > out.txt";
    char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(tokens->size, 5);
    cr_assert_eq(tokens->tokens[1].type, TOKEN_REDIRECT_IN);
    cr_assert_eq(tokens->tokens[3].type, TOKEN_REDIRECT_OUT);

    free_token_list(tokens);
}

Test(build_tokens_suite, here_doc_and_append) {
    char *input = "<< EOF >> append.txt";
    char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(tokens->size, 4);
    cr_assert_eq(tokens->tokens[0].type, TOKEN_HERE_DOC);
    cr_assert_eq(tokens->tokens[2].type, TOKEN_REDIRECT_APPEND);

    free_token_list(tokens);
}
