#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include "minishell.h"

Test(token_validation_suite, valid_simple_command)
{
	cr_redirect_stdout();
    char *input = "echo hello";
    char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(token_validation(tokens), 0);

    free_token_list(tokens);
}

Test(token_validation_suite, valid_pipe_sequence)
{
	cr_redirect_stdout();
    char *input = "ls | grep txt";
    char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(token_validation(tokens), 0);

    free_token_list(tokens);
}

Test(token_validation_suite, invalid_pipe_at_start)
{
	cr_redirect_stdout();
    char *input = "| ls";
    char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(token_validation(tokens), 1);

    free_token_list(tokens);
}

Test(token_validation_suite, invalid_pipe_at_end)
{
	cr_redirect_stdout();
    char *input = "ls |";
    char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(token_validation(tokens), 1);

    free_token_list(tokens);
}

Test(token_validation_suite, invalid_consecutive_pipes)
{
	cr_redirect_stdout();
    char *input = "ls || grep txt";
    char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(token_validation(tokens), 1);

    free_token_list(tokens);
}

Test(token_validation_suite, valid_redirection)
{
	cr_redirect_stdout();
    char *input = "cat < file.txt";
    char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(token_validation(tokens), 0);

    free_token_list(tokens);
}

Test(token_validation_suite, invalid_redirection_no_target)
{
	cr_redirect_stdout();
    char *input = "cat >";
    char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(token_validation(tokens), 1);

    free_token_list(tokens);
}

Test(token_validation_suite, invalid_redirection_followed_by_pipe)
{
	cr_redirect_stdout();
    char *input = "cat > | grep";
    char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(token_validation(tokens), 1);

    free_token_list(tokens);
}

Test(token_validation_suite, invalid_redirection_followed_by_redirection)
{
	cr_redirect_stdout();
    char *input = "echo hi > >> file";
    char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(token_validation(tokens), 1);

    free_token_list(tokens);
}
