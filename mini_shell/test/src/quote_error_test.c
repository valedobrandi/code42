#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../include/minishell.h"

Test(quote_error_suite, empty_string) {
    char *input = "";
    int output = quote_error(input);
    cr_assert_eq(output, 0);
}

Test(quote_error_suite, valid_single_quotes) {
    char *input = "'hello'";
    int output = quote_error(input);
    cr_assert_eq(output, 0);
}

Test(quote_error_suite, valid_double_quotes) {
    char *input = "\"hello\"";
    int output = quote_error(input);
    cr_assert_eq(output, 0);
}

Test(quote_error_suite, unclosed_single_quote) {
    char *input = "'hello";
    int output = quote_error(input);
    cr_assert_eq(output, 1);
}

Test(quote_error_suite, unclosed_double_quote) {
    char *input = "\"hello";
    int output = quote_error(input);
    cr_assert_eq(output, 1);
}

Test(quote_error_suite, single_quote_at_end) {
    char *input = "echo 'hello";
    int output = quote_error(input);
    cr_assert_eq(output, 1);
}

Test(quote_error_suite, double_quote_at_end) {
    char *input = "echo \"hello";
    int output = quote_error(input);
    cr_assert_eq(output, 1);
}

Test(quote_error_suite, mixed_quotes_unclosed) {
    char *input = "\"foo\" 'bar";
    int output = quote_error(input);
    cr_assert_eq(output, 1);
}

Test(quote_error_suite, nested_quotes_valid) {
    char *input = "'a \"b\" c'";
    int output = quote_error(input);
    cr_assert_eq(output, 0);
}

Test(quote_error_suite, only_one_single_quote) {
    char *input = "'";
    int output = quote_error(input);
    cr_assert_eq(output, 1);
}