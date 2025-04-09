#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include "libft.h"

/* ------------------ Output Tests ------------------ */

void test_ft_isalpha(void)
{
    printf("-> ft_isalpha\n");
    printf("a: %d\n", ft_isalpha('a'));
    printf("A: %d\n", ft_isalpha('A'));
    printf("1: %d\n", ft_isalpha('1'));
    printf("#: %d\n", ft_isalpha('#'));
    printf(" : %d\n", ft_isalpha(' '));
    printf("\n");
}

void test_ft_isdigit(void)
{
    printf("-> ft_isdigit\n");
    printf("0: %d\n", ft_isdigit('0'));
    printf("9: %d\n", ft_isdigit('9'));
    printf("a: %d\n", ft_isdigit('a'));
    printf(" : %d\n", ft_isdigit(' '));
    printf("\n");
}

void test_ft_isalnum(void)
{
    printf("-> ft_isalnum\n");
    printf("a: %d\n", ft_isalnum('a'));
    printf("Z: %d\n", ft_isalnum('Z'));
    printf("0: %d\n", ft_isalnum('0'));
    printf("9: %d\n", ft_isalnum('9'));
    printf("#: %d\n", ft_isalnum('#'));
    printf(" : %d\n", ft_isalnum(' '));
    printf("\n");
}

void test_ft_isascii(void)
{
    printf("-> ft_isascii\n");
    printf("a: %d\n", ft_isascii('a'));
    printf("0: %d\n", ft_isascii('0'));
    printf("DEL (127): %d\n", ft_isascii(127));
    printf("128: %d\n", ft_isascii(128));
    printf("-1: %d\n", ft_isascii(-1));
    printf("\n");
}

void test_ft_isprint(void)
{
    printf("-> isprint\n");
    printf("a: %d\n", ft_isprint('a'));
    printf("space: %d\n", ft_isprint(' '));
    printf("\\t: %d\n", ft_isprint('\t'));
    printf("DEL (127): %d\n", ft_isprint(127));
    printf("\n");
}

void test_ft_strlen(void)
{
    printf("-> ft_strlen\n");
    printf("Empty string: %d\n", ft_strlen(""));
    printf("Hello: %d\n", ft_strlen("Hello"));
    printf("Hello world!: %d\n", ft_strlen("Hello world!"));
    printf("\n");
}

void test_ft_memset(void)
{
    printf("-> ft_memset\n");
    char str[20] = "Hello World";
    printf("Before: %s\n", str);
    ft_memset(str, '*', 5);
    printf("After: %s\n", str);
    printf("\n");
}

void test_ft_bzero(void)
{
    printf("-> ft_bzero\n");
    char str[20] = "Hello World";
    printf("Before: %s\n", str);
    ft_bzero(str, 5);
    printf("After (as hex): ");
    for (int i = 0; i < 11; i++) {
        printf("%02x ", (unsigned char)str[i]);
    }
    printf("\n\n");
}

void test_ft_memcpy(void)
{
    printf("-> ft_memcpy\n");
    char src[20] = "Hello World";
    char dest[20] = "...............";
    printf("Before: src = %s, dest = %s\n", src, dest);
    ft_memcpy(dest, src, 11);
    printf("After: dest = %s\n", dest);
    printf("\n");
}

void test_ft_memmove(void)
{
    printf("-> ft_memmove\n");
    char str[20] = "Hello World";
    printf("Before: %s\n", str);
    ft_memmove(str + 6, str, 5);
    printf("After overlapping move: %s\n", str);
    printf("\n");
}

void test_ft_strlcpy(void)
{
    printf("-> ft_strlcpy\n");
    char src[20] = "Hello World";
    char dest[20];
    size_t len;
    
    len = ft_strlcpy(dest, src, 20);
    printf("Full copy: dest = \"%s\", len = %zu\n", dest, len);
    
    len = ft_strlcpy(dest, src, 6);
    printf("Partial copy: dest = \"%s\", len = %zu\n", dest, len);
    
    len = ft_strlcpy(dest, src, 0);
    printf("Zero-size copy: dest unchanged, len = %zu\n", len);
    printf("\n");
}

void test_ft_strlcat(void)
{
    printf("-> ft_strlcat\n");
    char dest1[20] = "Hello";
    char dest2[20] = "Hello";
    size_t len;
    
    len = ft_strlcat(dest1, " World", 20);
    printf("Normal concat: dest = \"%s\", len = %zu\n", dest1, len);
    
    len = ft_strlcat(dest2, " World", 8);
    printf("Size-limited concat: dest = \"%s\", len = %zu\n", dest2, len);
    printf("\n");
}

void test_ft_toupper(void)
{
    printf("-> ft_toupper\n");
    printf("a -> %c\n", ft_toupper('a'));
    printf("z -> %c\n", ft_toupper('z'));
    printf("A -> %c\n", ft_toupper('A'));
    printf("Z -> %c\n", ft_toupper('Z'));
    printf("0 -> %c\n", ft_toupper('0'));
    printf("space -> '%c'\n", ft_toupper(' '));
    printf("\n");
}

void test_ft_tolower(void)
{
    printf("-> ft_tolower\n");
    printf("A -> %c\n", ft_tolower('A'));
    printf("Z -> %c\n", ft_tolower('Z'));
    printf("a -> %c\n", ft_tolower('a'));
    printf("z -> %c\n", ft_tolower('z'));
    printf("0 -> %c\n", ft_tolower('0'));
    printf("space -> '%c'\n", ft_tolower(' '));
    printf("\n");
}

void test_ft_strchr(void)
{
    printf("-> ft_strchr\n");
    const char *str = "Hello World";
    printf("Search 'W' in \"%s\": %s\n", str, ft_strchr(str, 'W'));
    printf("Search 'o' in \"%s\": %s\n", str, ft_strchr(str, 'o'));
    printf("Search 'z' in \"%s\": %s\n", str, ft_strchr(str, 'z'));
    printf("Search '\\0' in \"%s\": %s\n", str, ft_strchr(str, '\0'));
    printf("\n");
}

void test_ft_strrchr(void)
{
    printf("-> ft_strrchr\n");
    const char *str = "Hello World";
    printf("Search last 'l' in \"%s\": %s\n", str, ft_strrchr(str, 'l'));
    printf("Search last 'o' in \"%s\": %s\n", str, ft_strrchr(str, 'o'));
    printf("Search last 'z' in \"%s\": %s\n", str, ft_strrchr(str, 'z'));
    printf("Search last '\\0' in \"%s\": %s\n", str, ft_strrchr(str, '\0'));
    printf("\n");
}

void test_ft_strncmp(void)
{
    printf("-> ft_strncmp\n");
    printf("test 1: %d\n", ft_strncmp("hello world", "hello world", 11));
    printf("test 2: %d\n", ft_strncmp("abc", "abd", 3));
    printf("test 3: %d\n", ft_strncmp("abc", "abc", 2));
    printf("test 4: %d\n", ft_strncmp("abc", "abcd", 3));
    printf("test 5: %d\n", ft_strncmp("abcd", "abc", 4));
    printf("test 6: %d\n", ft_strncmp("", "", 0));
    printf("\n");
}

void test_ft_memchr(void)
{
    printf("-> ft_memchr\n");
    const char str[] = "Hello World";
    printf("Search 'W': %s\n", (char *)ft_memchr(str, 'W', 11));
    printf("Search 'o': %s\n", (char *)ft_memchr(str, 'o', 11));
    printf("Search 'z': %p\n", ft_memchr(str, 'z', 11));
    printf("Search '\\0': %s\n", (char *)ft_memchr(str, '\0', 12));
    printf("\n");
}

void test_ft_memcmp(void)
{
    printf("-> ft_memcmp\n");
    printf("test 1: %d\n", ft_memcmp("hello", "hello", 5));
    printf("test 2: %d\n", ft_memcmp("hello", "hellp", 5));
    printf("test 3: %d\n", ft_memcmp("abcd", "abce", 4));
    printf("test 4: %d\n", ft_memcmp("test", "testa", 4));
    printf("test 5: %d\n", ft_memcmp("", "", 0));
    printf("\n");
}

void test_ft_strnstr(void)
{
    printf("-> ft_strnstr\n");
    printf("Find \"World\" in \"Hello World\": %s\n", ft_strnstr("Hello World", "World"));
    printf("Find \"Hello\" in \"Hello World\": %s\n", ft_strnstr("Hello World", "Hello"));
    printf("Find \"lo\" in \"Hello World\": %s\n", ft_strnstr("Hello World", "lo"));
    printf("Find \"xyz\" in \"Hello World\": %s\n", ft_strnstr("Hello World", "xyz"));
    printf("Find \"\" in \"Hello World\": %s\n", ft_strnstr("Hello World", ""));
    printf("\n");
}

void test_ft_atoi(void)
{
    printf("-> ft_atoi\n");
    printf("\"42\": %d\n", ft_atoi("42"));
    printf("\"-42\": %d\n", ft_atoi("-42"));
    printf("\"   +42\": %d\n", ft_atoi("   +42"));
    printf("\"\\t\\n\\v\\f\\r 42\": %d\n", ft_atoi("\t\n\v\f\r 42"));
    printf("\"   -42abc\": %d\n", ft_atoi("   -42abc"));
    printf("\"2147483647\": %d\n", ft_atoi("2147483647"));
    printf("\"-2147483648\": %d\n", ft_atoi("-2147483648"));
    printf("\n");
}

void test_ft_calloc(void)
{
    printf("-> ft_calloc\n");
    char *ptr = ft_calloc(10, sizeof(char));
    printf("Allocated 10 bytes, first 5 values: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);
    }
    free(ptr);
    printf("\n\n");
}

void test_ft_strdup(void)
{
    printf("-> ft_strdup\n");
    char *original = "Hello World";
    char *dup = ft_strdup(original);
    printf("Original: %s\n", original);
    printf("Duplicate: %s\n", dup);
    printf("Are pointers different? %s\n", (original != dup) ? "Yes" : "No");
    free(dup);
    printf("\n");
}

void test_ft_substr(void)
{
    printf("-> ft_substr\n");
    char *str = "Hello World";
    char *sub1 = ft_substr(str, 6, 5);    // "World"
    char *sub2 = ft_substr(str, 0, 5);    // "Hello"
    char *sub3 = ft_substr(str, 3, 5);    // "lo Wo"
    char *sub4 = ft_substr(str, 12, 5);   // "" (out of bounds)
    
    printf("Original: \"%s\"\n", str);
    printf("Substring (6, 5): \"%s\"\n", sub1);
    printf("Substring (0, 5): \"%s\"\n", sub2);
    printf("Substring (3, 5): \"%s\"\n", sub3);
    printf("Substring (12, 5): \"%s\"\n", sub4);
    
    free(sub1);
    free(sub2);
    free(sub3);
    free(sub4);
    printf("\n");
}

void test_ft_strjoin(void)
{
    printf("-> ft_strjoin\n");
    char *join1 = ft_strjoin("Hello", " World");
    char *join2 = ft_strjoin("", "Test");
    char *join3 = ft_strjoin("Test", "");
    char *join4 = ft_strjoin("", "");
    
    printf("Join \"Hello\" + \" World\": \"%s\"\n", join1);
    printf("Join \"\" + \"Test\": \"%s\"\n", join2);
    printf("Join \"Test\" + \"\": \"%s\"\n", join3);
    printf("Join \"\" + \"\": \"%s\"\n", join4);
    
    free(join1);
    free(join2);
    free(join3);
    free(join4);
    printf("\n");
}

void test_ft_strtrim(void)
{
    printf("-> ft_strtrim\n");
    char *trim1 = ft_strtrim("   Hello World   ", " ");
    char *trim2 = ft_strtrim("...Hello World...", ".");
    char *trim3 = ft_strtrim("abcHello Worldabc", "abc");
    char *trim4 = ft_strtrim("", "abc");
    char *trim5 = ft_strtrim("abcabc", "abc");
    
    printf("Trim \" \" from \"   Hello World   \": \"%s\"\n", trim1);
    printf("Trim \".\" from \"...Hello World...\": \"%s\"\n", trim2);
    printf("Trim \"abc\" from \"abcHello Worldabc\": \"%s\"\n", trim3);
    printf("Trim \"abc\" from \"\": \"%s\"\n", trim4);
    printf("Trim \"abc\" from \"abcabc\": \"%s\"\n", trim5);
    
    free(trim1);
    free(trim2);
    free(trim3);
    free(trim4);
    free(trim5);
    printf("\n");
}

void test_ft_split(void)
{
    printf("-> ft_split\n");
    char **split1 = ft_split("Hello World Test", ' ');
    char **split2 = ft_split(",,Hello,World,Test,,", ',');
    char **split3 = ft_split("", ',');
    char **split4 = ft_split("NoDelimiters", ' ');
    
    printf("Split \"Hello World Test\" by ' ':\n");
    for (int i = 0; split1[i]; i++) {
        printf("  [%d]: \"%s\"\n", i, split1[i]);
    }
    
    printf("Split \",,Hello,World,Test,,\" by ',':\n");
    for (int i = 0; split2[i]; i++) {
        printf("  [%d]: \"%s\"\n", i, split2[i]);
    }
    
    printf("Split \"\" by ',':\n");
    for (int i = 0; split3[i]; i++) {
        printf("  [%d]: \"%s\"\n", i, split3[i]);
    }
    
    printf("Split \"NoDelimiters\" by ' ':\n");
    for (int i = 0; split4[i]; i++) {
        printf("  [%d]: \"%s\"\n", i, split4[i]);
    }
    
    // Free all allocated memory
    for (int i = 0; split1[i]; i++) free(split1[i]);
    free(split1);
    
    for (int i = 0; split2[i]; i++) free(split2[i]);
    free(split2);
    
    for (int i = 0; split3[i]; i++) free(split3[i]);
    free(split3);
    
    for (int i = 0; split4[i]; i++) free(split4[i]);
    free(split4);
    
    printf("\n");
}

void test_ft_itoa(void)
{
    printf("-> ft_itoa\n");
    printf("42: \"%s\"\n", ft_itoa(42));
    printf("-42: \"%s\"\n", ft_itoa(-42));
    printf("0: \"%s\"\n", ft_itoa(0));
    printf("2147483647: \"%s\"\n", ft_itoa(2147483647));
    printf("-2147483648: \"%s\"\n", ft_itoa(-2147483648));
    printf("\n");
}

char test_strmapi_func(unsigned int i, char c)
{
    return c + i;
}

void test_ft_strmapi(void)
{
    printf("-> ft_strmapi\n");
    char *result = ft_strmapi("abc", test_strmapi_func);
    printf("Mapping \"abc\" with i+c: \"%s\"\n", result);
    free(result);
    printf("\n");
}

void test_striteri_func(unsigned int i, char *c)
{
    if (i % 2 == 0)
        *c = toupper(*c);
}

void test_ft_striteri(void)
{
    printf("-> ft_striteri\n");
    char str[] = "hello world";
    printf("Before: \"%s\"\n", str);
    ft_striteri(str, test_striteri_func);
    printf("After (uppercase even indices): \"%s\"\n", str);
    printf("\n");
}

void test_ft_putchar_fd(void)
{
    printf("-> ft_putchar_fd\n");
    printf("Writing 'A' to stdout: ");
    ft_putchar_fd('A', 1);
    printf("\n\n");
}

void test_ft_putstr_fd(void)
{
    printf("-> ft_putstr_fd\n");
    printf("Writing \"Hello World\" to stdout: ");
    ft_putstr_fd("Hello World", 1);
    printf("\n\n");
}

void test_ft_putendl_fd(void)
{
    printf("-> ft_putendl_fd\n");
    printf("Writing \"Hello World\" with newline to stdout: ");
    ft_putendl_fd("Hello World", 1);
    printf("\n");
}

void test_ft_putnbr_fd(void)
{
    printf("-> ft_putnbr_fd\n");
    printf("Writing 42 to stdout: ");
    ft_putnbr_fd(42, 1);
    printf("\nWriting -42 to stdout: ");
    ft_putnbr_fd(-42, 1);
    printf("\nWriting 0 to stdout: ");
    ft_putnbr_fd(0, 1);
    printf("\nWriting 2147483647 to stdout: ");
    ft_putnbr_fd(2147483647, 1);
    printf("\nWriting -2147483648 to stdout: ");
    ft_putnbr_fd(-2147483648, 1);
    printf("\n\n");
}

int main(void)
{
    test_ft_isalpha();
    test_ft_isdigit();
    test_ft_isalnum();
    test_ft_isascii();
    test_ft_isprint();
    test_ft_strlen();
    test_ft_memset();
    test_ft_bzero();
    test_ft_memcpy();
    test_ft_memmove();
    test_ft_strlcpy();
    test_ft_strlcat();
    test_ft_toupper();
    test_ft_tolower();
    test_ft_strchr();
    test_ft_strrchr();
    test_ft_strncmp();
    test_ft_memchr();
    test_ft_memcmp();
    test_ft_strnstr();
    test_ft_atoi();
    test_ft_strmapi();
    test_ft_striteri();
    test_ft_putchar_fd();
    test_ft_putstr_fd();
    test_ft_putendl_fd();
    test_ft_putnbr_fd();
    return 0;
}