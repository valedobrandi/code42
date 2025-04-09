#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <limits.h>

int test_printf_c()
{
    char ft_output[1024];
    char std_output[1024];

    // Test 1
    printf("Test 1: printf with \"%%c\", '0'\n");
    snprintf(ft_output, sizeof(ft_output), "%c", '0');
    snprintf(std_output, sizeof(std_output), "%c", '0');
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅");
    } else {
        printf("❌");
    }
    printf("\n\n");

    // Test 2
    printf("Test 2: printf with \" %%c \", '0'\n");
    snprintf(ft_output, sizeof(ft_output), " %c ", '0');
    snprintf(std_output, sizeof(std_output), " %c ", '0');
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅");
    } else {
        printf("❌");
    }
    printf("\n\n");

    // Test 3
    printf("Test 3: printf with \" %%c\", '0' - 256\n");
    snprintf(ft_output, sizeof(ft_output), " %c", '0' - 256);
    snprintf(std_output, sizeof(std_output), " %c", '0' - 256);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅");
    } else {
        printf("❌");
    }
    printf("\n\n");

    // Test 4
    printf("Test 4: printf with \"%%c \", '0' + 256\n");
    snprintf(ft_output, sizeof(ft_output), "%c ", '0' + 256);
    snprintf(std_output, sizeof(std_output), "%c ", '0' + 256);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅");
    } else {
        printf("❌");
    }
    printf("\n\n");

    // Test 5
    printf("Test 5: printf with \" %%c %%c %%c \", '0', 0, '1'\n");
    snprintf(ft_output, sizeof(ft_output), " %c %c %c ", '0', 0, '1');
    snprintf(std_output, sizeof(std_output), " %c %c %c ", '0', 0, '1');
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅");
    } else {
        printf("❌");
    }
    printf("\n\n");

    // Test 6
    printf("Test 6: printf with \" %%c %%c %%c \", ' ', ' ', ' '\n");
    snprintf(ft_output, sizeof(ft_output), " %c %c %c ", ' ', ' ', ' ');
    snprintf(std_output, sizeof(std_output), " %c %c %c ", ' ', ' ', ' ');
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅");
    } else {
        printf("❌");
    }
    printf("\n\n");

    // Test 7
    printf("Test 7: printf with \" %%c %%c %%c \", '1', '2', '3'\n");
    snprintf(ft_output, sizeof(ft_output), " %c %c %c ", '1', '2', '3');
    snprintf(std_output, sizeof(std_output), " %c %c %c ", '1', '2', '3');
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅");
    } else {
        printf("❌");
    }
    printf("\n\n");

    // Test 8
    printf("Test 8: printf with \" %%c %%c %%c \", '2', '1', 0\n");
    snprintf(ft_output, sizeof(ft_output), " %c %c %c ", '2', '1', 0);
    snprintf(std_output, sizeof(std_output), " %c %c %c ", '2', '1', 0);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅");
    } else {
        printf("❌");
    }
    printf("\n\n");

    // Test 9
    printf("Test 9: printf with \" %%c %%c %%c \", 0, '1', '2'\n");
    snprintf(ft_output, sizeof(ft_output), " %c %c %c ", 0, '1', '2');
    snprintf(std_output, sizeof(std_output), " %c %c %c ", 0, '1', '2');
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅");
    } else {
        printf("❌");
    }
    printf("\n\n");

    // Test 1: left-justified character
    printf("Test 1: ft_printf with \"%%-2c \", '0'\n");
    printf("[ %-2c ]\n", '0');
    ft_printf("[ %-2c ]\n", '0');

    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ Passed\n");
    } else {
        printf("❌ Failed\n");
    }

    // Test 2: left-justified character
    printf("Test 1: ft_printf with \" c c c \", '0'\n");
    printf("printf - [ %c %c %c ]\n", '0', 0, '1');
    ft_printf("ft_printf - [ %c %c %c ]\n", '0', 0, '1');

    return 0;
}

int main(void) {
    test_printf_c();
    return 0;
}