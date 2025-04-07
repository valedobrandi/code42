#include "ft_printf/libftprintf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdint.h>

int main(void) {
    // Testing: Print a simple string
    printf("Testing printf with \"Hello World\":\n");
    ft_printf("Hello World\n");
    printf("Expected output: Hello World\n\n");

    // Testing: Print a single character
    printf("Testing printf with character 'A':\n");
    ft_printf("%c\n", 'A');
    printf("Expected output: A\n\n");

    // Testing: Print a string
    printf("Testing printf with string \"Hello, World!\":\n");
    ft_printf("%s\n", "Hello, World!");
    printf("Expected output: Hello, World!\n\n");

    // Testing: Print a pointer address (e.g., 0x123abc)
    printf("Testing printf with pointer address 0x123abc:\n");
    ft_printf("%p\n", (void *)0x123abc);
    printf("Expected output: 0x123abc\n\n");

    // Testing: Print a signed integer (-1)
    printf("Testing printf with signed integer -1:\n");
    ft_printf("%d\n", -1);
    printf("Expected output: -1\n\n");

    // Testing: Print a signed integer (1)
    printf("Testing printf with signed integer 1:\n");
    ft_printf("%d\n", 1);
    printf("Expected output: 1\n\n");

    // Testing: Print another signed integer (-42)
    printf("Testing printf with signed integer -42:\n");
    ft_printf("%i\n", -42);
    printf("Expected output: -42\n\n");

    // Testing: Print an unsigned integer (42)
    printf("Testing printf with unsigned integer 42:\n");
    ft_printf("%u\n", 42);
    printf("Expected output: 42\n\n");

    // Testing: Print a hexadecimal number (lowercase) - 255
    printf("Testing printf with hexadecimal (lowercase) 255:\n");
    ft_printf("%x\n", 255);
    printf("Expected output: ff\n\n");

    // Testing: Print a hexadecimal number (uppercase) - 255
    printf("Testing printf with hexadecimal (uppercase) 255:\n");
    ft_printf("%X\n", 255);
    printf("Expected output: FF\n\n");

    // Testing: Print another character 'Z'
    printf("Testing printf with character 'Z':\n");
    ft_printf("%c\n", 'Z');
    printf("Expected output: Z\n\n");

    // Testing: Print a percent sign
    printf("Testing printf with percent sign %%:\n");
    ft_printf("%%\n");
    printf("Expected output: %%\n\n");

    // Add more tests for edge cases

    // Testing: Print a large integer (max int)
    printf("Testing printf with large signed integer (2147483647):\n");
    ft_printf("%d\n", 2147483647);
    printf("Expected output: 2147483647\n\n");

    // Testing: Print a negative large integer (-2147483648)
    printf("Testing printf with large negative signed integer (-2147483648):\n");
    ft_printf("%d\n", -2147483648);
    printf("Expected output: -2147483648\n\n");

    // Testing: Print a large unsigned integer (max unsigned int)
    printf("Testing printf with large unsigned integer (4294967295):\n");
    ft_printf("%u\n", 4294967295);
    printf("Expected output: 4294967295\n\n");

    // Testing: Print zero as a signed integer
    printf("Testing printf with zero as signed integer:\n");
    ft_printf("%d\n", 0);
    printf("Expected output: 0\n\n");

    return 0;
}
