#include "ft_printf/libft_printf.h"
#include "libft/libft.h"

int	main(void)
{
	ft_printf("Hello World\n");
    ft_printf("%c\n", 'A');  // Print character
    ft_printf("%s\n", "Hello, World!");  // Print string
    ft_printf("%p\n", (void *)0x123abc);  // Print pointer address
	ft_printf("%d\n", -1);
	ft_printf("%d\n", 1);
    ft_printf("%i\n", -42);  // Print signed integer
    ft_printf("%u\n", 42);  // Print unsigned integer
    ft_printf("%x\n", 255);  // Print hexadecimal (lowercase)
    ft_printf("%X\n", 255);  // Print hexadecimal (uppercase)
    ft_printf("%c\n", 'Z');  // Print another character
    ft_printf("%%\n");  // Print percent sign
	return (0);
}