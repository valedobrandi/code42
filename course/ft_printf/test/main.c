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
    return 0;
}

int test_ftprintf()
{
    char ft_output[1024];
    char std_output[1024];

    // Test 1
    printf("Test 1: printf with \" %%d \", 0\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", 0);
    snprintf(std_output, sizeof(std_output), " %d ", 0);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 2
    printf("Test 2: printf with \" %%d \", -1\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", -1);
    snprintf(std_output, sizeof(std_output), " %d ", -1);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 3
    printf("Test 3: printf with \" %%d \", 1\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", 1);
    snprintf(std_output, sizeof(std_output), " %d ", 1);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 4
    printf("Test 4: printf with \" %%d \", 9\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", 9);
    snprintf(std_output, sizeof(std_output), " %d ", 9);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 5
    printf("Test 5: printf with \" %%d \", 10\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", 10);
    snprintf(std_output, sizeof(std_output), " %d ", 10);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 6
    printf("Test 6: printf with \" %%d \", 11\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", 11);
    snprintf(std_output, sizeof(std_output), " %d ", 11);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 7
    printf("Test 7: printf with \" %%d \", 15\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", 15);
    snprintf(std_output, sizeof(std_output), " %d ", 15);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 8
    printf("Test 8: printf with \" %%d \", 16\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", 16);
    snprintf(std_output, sizeof(std_output), " %d ", 16);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 9
    printf("Test 9: printf with \" %%d \", 17\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", 17);
    snprintf(std_output, sizeof(std_output), " %d ", 17);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 10
    printf("Test 10: printf with \" %%d \", 99\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", 99);
    snprintf(std_output, sizeof(std_output), " %d ", 99);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 11
    printf("Test 11: printf with \" %%d \", 100\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", 100);
    snprintf(std_output, sizeof(std_output), " %d ", 100);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 12
    printf("Test 12: printf with \" %%d \", 101\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", 101);
    snprintf(std_output, sizeof(std_output), " %d ", 101);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 13
    printf("Test 13: printf with \" %%d \", -9\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", -9);
    snprintf(std_output, sizeof(std_output), " %d ", -9);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 14
    printf("Test 14: printf with \" %%d \", -10\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", -10);
    snprintf(std_output, sizeof(std_output), " %d ", -10);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 15
    printf("Test 15: printf with \" %%d \", -11\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", -11);
    snprintf(std_output, sizeof(std_output), " %d ", -11);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 16
    printf("Test 16: printf with \" %%d \", -14\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", -14);
    snprintf(std_output, sizeof(std_output), " %d ", -14);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 17
    printf("Test 17: printf with \" %%d \", -15\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", -15);
    snprintf(std_output, sizeof(std_output), " %d ", -15);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 18
    printf("Test 18: printf with \" %%d \", -16\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", -16);
    snprintf(std_output, sizeof(std_output), " %d ", -16);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 19
    printf("Test 19: printf with \" %%d \", -99\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", -99);
    snprintf(std_output, sizeof(std_output), " %d ", -99);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 20
    printf("Test 20: printf with \" %%d \", -100\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", -100);
    snprintf(std_output, sizeof(std_output), " %d ", -100);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 21
    printf("Test 21: printf with \" %%d \", -101\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", -101);
    snprintf(std_output, sizeof(std_output), " %d ", -101);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 22
    printf("Test 22: printf with \" %%d \", INT_MAX\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", INT_MAX);
    snprintf(std_output, sizeof(std_output), " %d ", INT_MAX);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 23
    printf("Test 23: printf with \" %%d \", INT_MIN\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", INT_MIN);
    snprintf(std_output, sizeof(std_output), " %d ", INT_MIN);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 24
    printf("Test 24: printf with \" %%d \", LONG_MAX\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", LONG_MAX);
    snprintf(std_output, sizeof(std_output), " %d ", LONG_MAX);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 25
    printf("Test 25: printf with \" %%d \", LONG_MIN\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", LONG_MIN);
    snprintf(std_output, sizeof(std_output), " %d ", LONG_MIN);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 26
    printf("Test 26: printf with \" %%d \", UINT_MAX\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", UINT_MAX);
    snprintf(std_output, sizeof(std_output), " %d ", UINT_MAX);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 27
    printf("Test 27: printf with \" %%d \", ULONG_MAX\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", ULONG_MAX);
    snprintf(std_output, sizeof(std_output), " %d ", ULONG_MAX);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 28
    printf("Test 28: printf with \" %%d \", 9223372036854775807LL\n");
    snprintf(ft_output, sizeof(ft_output), " %d ", 9223372036854775807LL);
    snprintf(std_output, sizeof(std_output), " %d ", 9223372036854775807LL);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");

    // Test 29
    printf("Test 29: printf with \" %%d %%d %%d %%d %%d %%d %%d\", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42\n");
    snprintf(ft_output, sizeof(ft_output), " %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    snprintf(std_output, sizeof(std_output), " %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("ft_output: [%s] ", ft_output);
    printf("std_output: [%s] ", std_output);
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");
    return 0;
}

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
    //test_printf_c();
    test_ftprintf_p();

    return 0;
}
