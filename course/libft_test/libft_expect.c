#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

/* ------------------ Expected Tests ------------------ */

void test_isalpha(void)
{
    printf("-> isalpha\n");
    printf("a: %d\n", isalpha('a'));
    printf("A: %d\n", isalpha('A'));
    printf("1: %d\n", isalpha('1'));
    printf("#: %d\n", isalpha('#'));
    printf(" : %d\n", isalpha(' '));
    printf("\n");
}

void test_isdigit(void)
{
    printf("-> isdigit\n");
    printf("0: %d\n", isdigit('0'));
    printf("9: %d\n", isdigit('9'));
    printf("a: %d\n", isdigit('a'));
    printf(" : %d\n", isdigit(' '));
    printf("\n");
}

void test_isalnum(void)
{
    printf("-> isalnum\n");
    printf("a: %d\n", isalnum('a'));
    printf("Z: %d\n", isalnum('Z'));
    printf("0: %d\n", isalnum('0'));
    printf("9: %d\n", isalnum('9'));
    printf("#: %d\n", isalnum('#'));
    printf(" : %d\n", isalnum(' '));
    printf("\n");
}

void test_isascii(void)
{
    printf("-> isascii\n");
    printf("a: %d\n", isascii('a'));
    printf("0: %d\n", isascii('0'));
    printf("DEL (127): %d\n", isascii(127));
    printf("128: %d\n", isascii(128));
    printf("-1: %d\n", isascii(-1));
    printf("\n");
}

void test_isprint(void)
{
    printf("-> isprint\n");
    printf("a: %d\n", isprint('a'));
    printf("space: %d\n", isprint(' '));
    printf("\\t: %d\n", isprint('\t'));
    printf("DEL (127): %d\n", isprint(127));
    printf("\n");
}

void test_strlen(void)
{
    printf("-> strlen\n");
    printf("Empty string: %d\n", (int)strlen(""));
    printf("Hello: %d\n", (int)strlen("Hello"));
    printf("Hello world!: %d\n", (int)strlen("Hello world!"));
    printf("\n");
}

void test_memset(void)
{
    printf("-> memset\n");
    char str[20] = "Hello World";
    printf("Before: %s\n", str);
    memset(str, '*', 5);
    printf("After: %s\n", str);
    printf("\n");
}

void test_bzero(void)
{
    printf("-> bzero\n");
    char str[20] = "Hello World";
    printf("Before: %s\n", str);
    bzero(str, 5);
    printf("After (as hex): ");
    for (int i = 0; i < 11; i++) {
        printf("%02x ", (unsigned char)str[i]);
    }
    printf("\n\n");
}

void test_memcpy(void)
{
    printf("-> memcpy\n");
    char src[20] = "Hello World";
    char dest[20] = "...............";
    printf("Before: src = %s, dest = %s\n", src, dest);
    memcpy(dest, src, 11);
    printf("After: dest = %s\n", dest);
    printf("\n");
}

void test_memmove(void)
{
    printf("-> memmove\n");
    char str[20] = "Hello World";
    printf("Before: %s\n", str);
    memmove(str + 6, str, 5);
    printf("After overlapping move: %s\n", str);
    printf("\n");
}

void test_strlcpy(void)
{
    printf("-> strlcpy\n");
    char src[20] = "Hello World";
    char dest[20];
    size_t len;
    
    len = strlcpy(dest, src, 20);
    printf("Full copy: dest = \"%s\", len = %zu\n", dest, len);
    
    len = strlcpy(dest, src, 6);
    printf("Partial copy: dest = \"%s\", len = %zu\n", dest, len);
    
    len = strlcpy(dest, src, 0);
    printf("Zero-size copy: dest unchanged, len = %zu\n", len);
    printf("\n");
}

void test_strlcat(void)
{
    printf("-> strlcat\n");
    char dest1[20] = "Hello";
    char dest2[20] = "Hello";
    size_t len;
    
    len = strlcat(dest1, " World", 20);
    printf("Normal concat: dest = \"%s\", len = %zu\n", dest1, len);
    
    len = strlcat(dest2, " World", 8);
    printf("Size-limited concat: dest = \"%s\", len = %zu\n", dest2, len);
    printf("\n");
}

void test_toupper(void)
{
    printf("-> toupper\n");
    printf("a -> %c\n", toupper('a'));
    printf("z -> %c\n", toupper('z'));
    printf("A -> %c\n", toupper('A'));
    printf("Z -> %c\n", toupper('Z'));
    printf("0 -> %c\n", toupper('0'));
    printf("space -> '%c'\n", toupper(' '));
    printf("\n");
}

void test_tolower(void)
{
    printf("-> tolower\n");
    printf("A -> %c\n", tolower('A'));
    printf("Z -> %c\n", tolower('Z'));
    printf("a -> %c\n", tolower('a'));
    printf("z -> %c\n", tolower('z'));
    printf("0 -> %c\n", tolower('0'));
    printf("space -> '%c'\n", tolower(' '));
    printf("\n");
}

void test_strchr(void)
{
    printf("-> strchr\n");
    const char *str = "Hello World";
    printf("Search 'W' in \"%s\": %s\n", str, strchr(str, 'W'));
    printf("Search 'o' in \"%s\": %s\n", str, strchr(str, 'o'));
    printf("Search 'z' in \"%s\": %s\n", str, strchr(str, 'z'));
    printf("Search '\\0' in \"%s\": %s\n", str, strchr(str, '\0'));
    printf("\n");
}

void test_strrchr(void)
{
    printf("-> strrchr\n");
    const char *str = "Hello World";
    printf("Search last 'l' in \"%s\": %s\n", str, strrchr(str, 'l'));
    printf("Search last 'o' in \"%s\": %s\n", str, strrchr(str, 'o'));
    printf("Search last 'z' in \"%s\": %s\n", str, strrchr(str, 'z'));
    printf("Search last '\\0' in \"%s\": %s\n", str, strrchr(str, '\0'));
    printf("\n");
}

void test_strncmp(void)
{
    printf("-> strncmp\n");
    printf("test 1: %d\n", strncmp("hello world", "hello world", 11));
    printf("test 2: %d\n", strncmp("abc", "abd", 3));
    printf("test 3: %d\n", strncmp("abc", "abc", 2));
    printf("test 4: %d\n", strncmp("abc", "abcd", 4));
    printf("test 5: %d\n", strncmp("abcd", "abc", 4));
    printf("test 6: %d\n", strncmp("", "", 0));
    printf("\n");
}

void test_memchr(void)
{
    printf("-> memchr\n");
    const char str[] = "Hello World";
    printf("Search 'W': %s\n", (char *)memchr(str, 'W', 11));
    printf("Search 'o': %s\n", (char *)memchr(str, 'o', 11));
    printf("Search 'z': %p\n", memchr(str, 'z', 11));
    printf("Search '\\0': %s\n", (char *)memchr(str, '\0', 12));
    printf("\n");
}

void test_memcmp(void)
{
    printf("-> memcmp\n");
    printf("test 1: %d\n", memcmp("hello", "hello", 5));
    printf("test 2: %d\n", memcmp("hello", "hellp", 5));
    printf("test 3: %d\n", memcmp("abcd", "abce", 4));
    printf("test 4: %d\n", memcmp("test", "testa", 4));
    printf("test 5: %d\n", memcmp("", "", 0));
    printf("\n");
}

void test_ft_strnstr(void)
{
    printf("-> strnstr\n");
    printf("Find \"World\" in \"Hello World\": %s\n", "World");
    printf("Find \"Hello\" in \"Hello World\": %s\n", "Hello World");
    printf("Find \"lo\" in \"Hello World\": %s\n", "lo World");
    printf("Find \"xyz\" in \"Hello World\": %s\n", "(null)");
    printf("Find \"\" in \"Hello World\": %s\n", "Hello World");
    printf("\n");
}

void test_atoi(void)
{
    printf("-> atoi\n");
    printf("\"42\": %d\n", atoi("42"));
    printf("\"-42\": %d\n", atoi("-42"));
    printf("\"   +42\": %d\n", atoi("   +42"));
    printf("\"\\t\\n\\v\\f\\r 42\": %d\n", atoi("\t\n\v\f\r 42"));
    printf("\"   -42abc\": %d\n", atoi("   -42abc"));
    printf("\"2147483647\": %d\n", atoi("2147483647"));
    printf("\"-2147483648\": %d\n", atoi("-2147483648"));
    printf("\n");
}

void test_ft_calloc(void)
{
    printf("-> calloc\n");
    printf("Allocated 10 bytes, first 5 values: 0 0 0 0 0\n\n");
    printf("\n");
}

void test_strdup(void)
{
    printf("-> strdup\n");
    printf("Original: Hello World\n");
    printf("Duplicate: Hello World\n");
    printf("Are pointers different? Yes\n\n");
    printf("\n");
}

void test_substr(void)
{
    printf("-> substr\n");
    printf("Original: \"Hello World\"\n");
    printf("Substring (6, 5): \"World\"\n");
    printf("Substring (0, 5): \"Hello\"\n");
    printf("Substring (3, 5): \"lo Wo\"\n");
    printf("Substring (12, 5): \"\"\n\n");;
    printf("\n");
}

void test_strjoin(void)
{
    printf("-> strjoin\n");
    printf("Join \"Hello\" + \" World\": \"Hello World\"\n");
    printf("Join \"\" + \"Test\": \"Test\"\n");
    printf("Join \"Test\" + \"\": \"Test\"\n");
    printf("Join \"\" + \"\": \"\"\n\n");
    printf("\n");
}

void test_strtrim(void)
{
    printf("-> strtrim\n");
    printf("Trim \" \" from \"   Hello World   \": \"Hello World\"\n");
    printf("Trim \".\" from \"...Hello World...\": \"Hello World\"\n");
    printf("Trim \"abc\" from \"abcHello Worldabc\": \"Hello World\"\n");
    printf("Trim \"abc\" from \"\": \"\"\n");
    printf("Trim \"abc\" from \"abcabc\": \"\"\n\n");
    printf("\n");
}

void test_split(void)
{
    printf("-> split\n");
    printf("Split \"Hello World Test\" by ' ':\n");
    printf("  [0]: \"Hello\"\n");
    printf("  [1]: \"World\"\n");
    printf("  [2]: \"Test\"\n");
    printf("\n");
}

void test_itoa(void)
{
    printf("-> itoa\n");
    printf("42: \"42\"\n");
    printf("-42: \"-42\"\n");
    printf("0: \"0\"\n");
    printf("2147483647: \"2147483647\"\n");
    printf("-2147483648: \"-2147483648\"\n\n");
    printf("\n");
}

void test_strmapi(void)
{
    printf("-> strmapi\n");
    printf("Mapping \"abc\" with i+c: \"ace\"\n\n");
    printf("\n");
}

void test_striteri(void)
{
    printf("-> striteri\n");
    printf("Before: \"hello world\"\n");
    printf("After (uppercase even indices): \"HeLlO WoRlD\"\n\n");
    printf("\n");
}

void test_putchar_fd(void)
{
    printf("-> putchar_fd\n");
    printf("Writing 'A' to stdout: A\n\n");
    printf("\n\n");
}

void test_putstr_fd(void)
{
    printf("-> putstr_fd\n");
    printf("Writing \"Hello World\" to stdout: Hello World\n\n");
    printf("\n\n");
}

void test_putendl_fd(void)
{
    printf("-> putendl_fd\n");
    printf("Writing \"Hello World\" with newline to stdout: Hello World\n\n");
    printf("\n");
}

void test_putnbr_fd(void)
{
    printf("-> putnbr_fd\n");
    printf("Writing 42 to stdout: 42\n");
    printf("Writing -42 to stdout: -42\n");
    printf("Writing 0 to stdout: 0\n");
    printf("Writing 2147483647 to stdout: 2147483647\n");
    printf("Writing -2147483648 to stdout: -2147483648\n\n");;
    printf("\n\n");
}

int main(void)
{
    test_isalpha();
    test_isdigit();
    test_isalnum();
    test_isascii();
    test_isprint();
    test_strlen();
    test_memset();
    test_bzero();
    test_memcpy();
    test_memmove();
    test_strlcpy();
    test_strlcat();
    test_toupper();
    test_tolower();
    test_strchr();
    test_strrchr();
    test_strncmp();
    test_memchr();
    test_memcmp();
    test_ft_strnstr();
    test_atoi();
    test_strmapi();
    test_striteri();
    return 0;
}