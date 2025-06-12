#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/new/assert.h>
#include "../include/minishell.h"

char **dup_arr(char **src);

void free_pipeline(t_pipeline *pipeline);

void setup_redirect(void)
{
    cr_redirect_stdout();
}

Test(execute_command_suite, echo_no_args, .init = cr_redirect_stdout) {

    char *input = "echo hello world";

    char **parse = parse_prompt(input);

    t_token_list *tokens = build_tokens(dup_arr(parse));

    t_pipeline *pipeline = build_pipeline(tokens);

    fflush(stdout);

    execute_command(pipeline);

    cr_assert_stdout_eq_str("hello world\n");

    free_array(parse);

    free_token_list(tokens);

    free_pipeline(pipeline);
}

Test(execute_command_suite, echo_no_args_quote, .init = cr_redirect_stdout) {

    char *input = "echo \"hello\"\"w\"";

    char **parse = parse_prompt(input);

    t_token_list *tokens = build_tokens(dup_arr(parse));

    t_pipeline *pipeline = build_pipeline(tokens);

    fflush(stdout);

    execute_command(pipeline);

    cr_assert_stdout_eq_str("hellow\n");

    free_array(parse);

    free_token_list(tokens);

    free_pipeline(pipeline);
}

Test(execute_command_suite, echo_args, .init = cr_redirect_stdout) {

    char *input = "echo -n hello world";

    char **parse = parse_prompt(input);

    t_token_list *tokens = build_tokens(dup_arr(parse));

    t_pipeline *pipeline = build_pipeline(tokens);

    fflush(stdout);

    execute_command(pipeline);

    cr_assert_stdout_eq_str("hello world");

    free_array(parse);

    free_token_list(tokens);

    free_pipeline(pipeline);
}