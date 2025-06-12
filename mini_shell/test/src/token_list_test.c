#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "minishell.h"

/*  SINGLE QUOTE */
Test(build_tokens_suite, single_quote) {
    char *input = "'hello word'";
	char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(tokens->size, 1);
    cr_assert_str_eq(tokens->tokens[0].value, "hello word");
    cr_assert_eq(tokens->tokens[0].type, TOKEN_WORD);

    free_token_list(tokens);
}

Test(build_tokens_suite, single_quote_dollar) {
    char *input = "'hello word $HOME'";
	char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(tokens->size, 1);
    cr_assert_str_eq(tokens->tokens[0].value, "hello word $HOME");
    cr_assert_eq(tokens->tokens[0].type, TOKEN_WORD);

    free_token_list(tokens);
}

Test(build_tokens_suite, single_quote_no_quote) {
    char *input = "w\"hello  word\"hi!";
	char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(tokens->size, 1);
    cr_assert_str_eq(tokens->tokens[0].value, "whello  wordhi!");
    cr_assert_eq(tokens->tokens[0].type, TOKEN_WORD);

    free_token_list(tokens);
}

Test(build_tokens_suite, single_quote_no_quote_complex) {
    char *input = "w\"hello  word\"hi!\"   newwod\"yes";
	char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(tokens->size, 1);
    cr_assert_str_eq(tokens->tokens[0].value, "whello  wordhi!   newwodyes");
    cr_assert_eq(tokens->tokens[0].type, TOKEN_WORD);

    free_token_list(tokens);
}

/*  DOUBLE QUOTE */

Test(build_tokens_suite, double_quote) {
    char *input = "\"hello word\"";
	char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(tokens->size, 1);
    cr_assert_str_eq(tokens->tokens[0].value, "hello word");
    cr_assert_eq(tokens->tokens[0].type, TOKEN_WORD);

    free_token_list(tokens);
}

Test(build_tokens_suite, double_quote_dollar) {
    char *input = "\"hello word $HOME\"";
	char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(tokens->size, 1);
    cr_assert_str_eq(tokens->tokens[0].value, "hello word HOME");
    cr_assert_eq(tokens->tokens[0].type, TOKEN_WORD);

    free_token_list(tokens);
}

Test(build_tokens_suite, double_quote_no_quote) {
    char *input = "w\"hello  word\"hi!";
	char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(tokens->size, 1);
    cr_assert_str_eq(tokens->tokens[0].value, "whello  wordhi!");
    cr_assert_eq(tokens->tokens[0].type, TOKEN_WORD);

    free_token_list(tokens);
}

Test(build_tokens_suite, double_quote_no_quote_complex) {
    char *input = "w\"hello  word\"hi!\"   newwod\"yes";
	char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(tokens->size, 1);
    cr_assert_str_eq(tokens->tokens[0].value, "whello  wordhi!   newwodyes");
    cr_assert_eq(tokens->tokens[0].type, TOKEN_WORD);

    free_token_list(tokens);
}

/*  NO QUOTE */

Test(build_tokens_suite, no_quote) {
    char *input = "echo";
	char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(tokens->size, 1);
    cr_assert_str_eq(tokens->tokens[0].value, "echo");
    cr_assert_eq(tokens->tokens[0].type, TOKEN_WORD);

    free_token_list(tokens);
}

Test(build_tokens_suite, no_quote_dollar) {
    char *input = "echo $HOME";
	char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(tokens->size, 2);
    cr_assert_str_eq(tokens->tokens[0].value, "echo");
	cr_assert_str_eq(tokens->tokens[1].value, "HOME");
    cr_assert_eq(tokens->tokens[0].type, TOKEN_WORD);
	cr_assert_eq(tokens->tokens[1].type, TOKEN_WORD);

    free_token_list(tokens);
}

/*  MIX QUOTE NO QUOTE */

Test(build_tokens_suite, no_quote_dollar_quote_dollar) {
    char *input = "echo $HOME \"$HOME:/path\" 'hello'";
	char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(tokens->size, 4);
    cr_assert_str_eq(tokens->tokens[0].value, "echo");
	cr_assert_str_eq(tokens->tokens[1].value, "HOME");
	cr_assert_str_eq(tokens->tokens[2].value, "HOME:/path");
	cr_assert_str_eq(tokens->tokens[3].value, "hello");
    cr_assert_eq(tokens->tokens[0].type, TOKEN_WORD);
	cr_assert_eq(tokens->tokens[1].type, TOKEN_WORD);
	cr_assert_eq(tokens->tokens[2].type, TOKEN_WORD);
	cr_assert_eq(tokens->tokens[3].type, TOKEN_WORD);

    free_token_list(tokens);
}

/*  ESPECIAL CASE $? */

Test(build_tokens_suite, especial_case_dollar) {
    char *input = "$?";
	char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(tokens->size, 1);
    cr_assert_str_eq(tokens->tokens[0].value, "\x1F");

    cr_assert_eq(tokens->tokens[0].type, TOKEN_WORD);


    free_token_list(tokens);
}

Test(build_tokens_suite, especial_case_mix_dollar) {
    char *input = "$?'$?'\"$?\"abc";
	char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    cr_assert_eq(tokens->size, 1);
    cr_assert_str_eq(tokens->tokens[0].value, "\x1F""$?""\x1F""abc");

    cr_assert_eq(tokens->tokens[0].type, TOKEN_WORD);


    free_token_list(tokens);
}

/* OPERATORS */
Test(build_tokens_suite, pipe_command) {
    char *input = "ls | grep txt";
    char **parse = parse_prompt(input);
    t_token_list *tokens = build_tokens(parse);

    cr_assert_not_null(tokens);
    //cr_assert_eq(tokens->size, 3);
	cr_assert_str_eq(tokens->tokens[0].value, "ls");
    cr_assert_eq(tokens->tokens[0].type, TOKEN_WORD);

    cr_assert_str_eq(tokens->tokens[1].value, "|");
    cr_assert_eq(tokens->tokens[1].type, TOKEN_PIPE);

	cr_assert_str_eq(tokens->tokens[2].value, "grep");
    cr_assert_eq(tokens->tokens[2].type, TOKEN_WORD);

    cr_assert_str_eq(tokens->tokens[3].value, "txt");
    cr_assert_eq(tokens->tokens[3].type, TOKEN_WORD);

    free_token_list(tokens);
}

/* Test(build_tokens_suite, redirections) {
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
 */