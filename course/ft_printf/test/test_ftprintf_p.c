#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <limits.h>

int test_ftprintf_p()
{
    #include <stdio.h>
    #include <string.h>
    #include <limits.h>

    char ft_output[1024];
    char std_output[1024];

    // Test 1
    printf("Test 1: printf with \" %%p \", -1\n");
    snprintf(ft_output, sizeof(ft_output), " %p ", (void *)-1);
    snprintf(std_output, sizeof(std_output), " %p ", (void *)-1);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 2
    printf("Test 2: printf with \" %%p \", 1\n");
    snprintf(ft_output, sizeof(ft_output), " %p ", (void *)1);
    snprintf(std_output, sizeof(std_output), " %p ", (void *)1);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 3
    printf("Test 3: printf with \" %%p \", 15\n");
    snprintf(ft_output, sizeof(ft_output), " %p ", (void *)15);
    snprintf(std_output, sizeof(std_output), " %p ", (void *)15);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 4
    printf("Test 4: printf with \" %%p \", 16\n");
    snprintf(ft_output, sizeof(ft_output), " %p ", (void *)16);
    snprintf(std_output, sizeof(std_output), " %p ", (void *)16);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 5
    printf("Test 5: printf with \" %%p \", 17\n");
    snprintf(ft_output, sizeof(ft_output), " %p ", (void *)17);
    snprintf(std_output, sizeof(std_output), " %p ", (void *)17);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 6
    printf("Test 6: printf with \" %%p %%p \", LONG_MIN, LONG_MAX\n");
    snprintf(ft_output, sizeof(ft_output), " %p %p ", (void *)LONG_MIN, (void *)LONG_MAX);
    snprintf(std_output, sizeof(std_output), " %p %p ", (void *)LONG_MIN, (void *)LONG_MAX);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 7
    printf("Test 7: printf with \" %%p %%p \", INT_MIN, INT_MAX\n");
    snprintf(ft_output, sizeof(ft_output), " %p %p ", (void *)(intptr_t)INT_MIN, (void *)(intptr_t)INT_MAX);
    snprintf(std_output, sizeof(std_output), " %p %p ", (void *)(intptr_t)INT_MIN, (void *)(intptr_t)INT_MAX);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 8
    printf("Test 8: printf with \" %%p %%p \", ULONG_MAX, -ULONG_MAX\n");
    snprintf(ft_output, sizeof(ft_output), " %p %p ", (void *)ULONG_MAX, (void *)-ULONG_MAX);
    snprintf(std_output, sizeof(std_output), " %p %p ", (void *)ULONG_MAX, (void *)-ULONG_MAX);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 9
    printf("Test 9: printf with \" %%p %%p \", 0, 0\n");
    snprintf(ft_output, sizeof(ft_output), " %p %p ", (void *)0, (void *)0);
    snprintf(std_output, sizeof(std_output), " %p %p ", (void *)0, (void *)0);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");
    return (0);
}

int main(void) {
    test_ftprintf_p();

    return 0;
}
