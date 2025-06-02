#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../include/minishell.h"

Test(parse_prompt_suite, empty_string) {
    char *input = "";
    char **tokens = parse_prompt(input);

    cr_assert_not_null(tokens);
    cr_assert_null(tokens[0]);

    free_array(tokens);
}

Test(parse_prompt_suite, simple_space_split) {
    char *input = "ls | grep txt";
    char **tokens = parse_prompt(input);

    cr_assert_not_null(tokens);
    cr_assert_str_eq(tokens[0], "ls");
    cr_assert_str_eq(tokens[1], "|");
    cr_assert_str_eq(tokens[2], "grep");
	cr_assert_str_eq(tokens[3], "txt");
    cr_assert_null(tokens[4]);

    free_array(tokens);
}

Test(parse_prompt_suite, handles_quotes) {
    char *input = "echo \"hello world\"";
    char **tokens = parse_prompt(input);

    cr_assert_not_null(tokens);
    cr_assert_str_eq(tokens[0], "echo");
    cr_assert_str_eq(tokens[1], "\"hello world\"");
    cr_assert_null(tokens[2]);

    free_array(tokens);
}


Test(parse_prompt_suite, mixed_quoted_space_and_unquoted) {
    char *input = "echo \"hello\" w\"\"";
    char **tokens = parse_prompt(input);

    cr_assert_not_null(tokens);
    cr_assert_str_eq(tokens[0], "echo");
    cr_assert_str_eq(tokens[1], "\"hello\"");
    cr_assert_str_eq(tokens[2], "w\"\"");
    cr_assert_null(tokens[3]);

    free_array(tokens);
}

Test(parse_prompt_suite, mixed_quoted_and_unquoted) {
    char *input = "echo \"hello\"w\"\"";
    char **tokens = parse_prompt(input);

    cr_assert_not_null(tokens);
    cr_assert_str_eq(tokens[0], "echo");
    cr_assert_str_eq(tokens[1], "\"hello\"w\"\"");
    cr_assert_null(tokens[2]);

    free_array(tokens);
}

Test(parse_prompt_suite, single_quotes_literal) {
    char *input = "echo 'hello $USER'";
    char **tokens = parse_prompt(input);

    cr_assert_not_null(tokens);
    cr_assert_str_eq(tokens[0], "echo");
    cr_assert_str_eq(tokens[1], "'hello $USER'");
    cr_assert_null(tokens[2]);

    free_array(tokens);
}

Test(parse_prompt_suite, double_quotes_allow_dollar) {
    char *input = "echo \"hello $USER\"";
    char **tokens = parse_prompt(input);

    cr_assert_not_null(tokens);
    cr_assert_str_eq(tokens[0], "echo");
    cr_assert_str_eq(tokens[1], "\"hello $USER\"");
    cr_assert_null(tokens[2]);

    free_array(tokens);
}

Test(parse_prompt_suite, quotes_and_spaces) {
    char *input = "   echo    \"hello   world\"   ";
    char **tokens = parse_prompt(input);

    cr_assert_not_null(tokens);
    cr_assert_str_eq(tokens[0], "echo");
    cr_assert_str_eq(tokens[1], "\"hello   world\"");
    cr_assert_null(tokens[2]);

    free_array(tokens);
}

Test(parse_prompt_suite, basic_redirection_syntax) {
    char *input = "cat < infile | grep hello > outfile";
    char **tokens = parse_prompt(input);

    cr_assert_str_eq(tokens[0], "cat");
    cr_assert_str_eq(tokens[1], "<");
    cr_assert_str_eq(tokens[2], "infile");
    cr_assert_str_eq(tokens[3], "|");
    cr_assert_str_eq(tokens[4], "grep");
    cr_assert_str_eq(tokens[5], "hello");
    cr_assert_str_eq(tokens[6], ">");
    cr_assert_str_eq(tokens[7], "outfile");
    cr_assert_null(tokens[8]);

    free_array(tokens);
}

Test(parse_prompt_suite, exit_status_token) {
    char *input = "echo $?";
    char **tokens = parse_prompt(input);

    cr_assert_str_eq(tokens[0], "echo");
    cr_assert_str_eq(tokens[1], "$?");
    cr_assert_null(tokens[2]);

    free_array(tokens);
}

Test(parse_prompt_suite, redirection_between_quoted_strings) {
    char *input = "echo \"hi\">\"out.txt\"";
    char **tokens = parse_prompt(input);

    cr_assert_not_null(tokens);
    cr_assert_str_eq(tokens[0], "echo");
    cr_assert_str_eq(tokens[1], "\"hi\"");
    cr_assert_str_eq(tokens[2], ">");
    cr_assert_str_eq(tokens[3], "\"out.txt\"");
    cr_assert_null(tokens[4]);

    free_array(tokens);
}

Test(parse_prompt_suite, redirection_inside_quotes) {
    char *input = "echo \">\" '<' \"<<\"";
    char **tokens = parse_prompt(input);

    cr_assert_not_null(tokens);
    cr_assert_str_eq(tokens[0], "echo");
    cr_assert_str_eq(tokens[1], "\">\"");
    cr_assert_str_eq(tokens[2], "'<'");
    cr_assert_str_eq(tokens[3], "\"<<\"");
    cr_assert_null(tokens[4]);

    free_array(tokens);
}


Test(parse_prompt_suite, only_spaces) {
    char *input = "     ";
    char **tokens = parse_prompt(input);

    cr_assert_not_null(tokens);
    cr_assert_null(tokens[0]);

    free_array(tokens);
}

Test(parse_prompt_suite, single_word) {
    char *input = "hello";
    char **tokens = parse_prompt(input);

    cr_assert_not_null(tokens);
    cr_assert_str_eq(tokens[0], "hello");
    cr_assert_null(tokens[1]);

    free_array(tokens);
}

Test(parse_prompt_suite, mixed_single_and_double_quotes) {
    char *input = "echo 'single quoted' \"double quoted\"";
    char **tokens = parse_prompt(input);

    cr_assert_not_null(tokens);
    cr_assert_str_eq(tokens[0], "echo");
    cr_assert_str_eq(tokens[1], "'single quoted'");
    cr_assert_str_eq(tokens[2], "\"double quoted\"");
    cr_assert_null(tokens[3]);

    free_array(tokens);
}

Test(parse_prompt_suite, nested_quotes_like_behavior) {
    char *input = "echo \"She said 'hello'\"";
    char **tokens = parse_prompt(input);

    cr_assert_not_null(tokens);
    cr_assert_str_eq(tokens[0], "echo");
    cr_assert_str_eq(tokens[1], "\"She said 'hello'\"");
    cr_assert_null(tokens[2]);

    free_array(tokens);
}

Test(parse_prompt_suite, multiple_spaces_between_words) {
    char *input = "echo    multiple     spaces";
    char **tokens = parse_prompt(input);

    cr_assert_not_null(tokens);
    cr_assert_str_eq(tokens[0], "echo");
    cr_assert_str_eq(tokens[1], "multiple");
    cr_assert_str_eq(tokens[2], "spaces");
    cr_assert_null(tokens[3]);

    free_array(tokens);
}
/*
Test(parse_prompt_suite, trailing_spaces) {
    char *input = "echo hello world    ";
    char **tokens = parse_prompt(input);

    cr_assert_not_null(tokens);
    cr_assert_str_eq(tokens[0], "echo");
    cr_assert_str_eq(tokens[1], "hello");
    cr_assert_str_eq(tokens[2], "world");
    cr_assert_null(tokens[3]);

    free_array(tokens);
}
 */




