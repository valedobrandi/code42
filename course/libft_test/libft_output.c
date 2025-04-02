
#include "libft.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

/* void test_ft_memcpy() {
	char src[] = "Hello, World!";
	char dest[20];

	ft_memcpy(dest, src, 5);
	dest[5] = '\0';
	assert(strcmp(dest, "Hello") == 0);

	ft_memcpy(dest, src, strlen(src) + 1);
	assert(strcmp(dest, src) == 0);
	printf("ft_memcpy OK!\n");
	printf("---\n");
}

void	test_memmove(void) {
	char str1[] = "123456789";


	memmove(str1 + 3, str1, 5);
	assert(strcmp(str1, "123123459") == 0);

	char str2[] = "Hello, World!";
	char dest[20];


	memmove(dest, str2, strlen(str2) + 1);
	assert(strcmp(dest, str2) == 0);

	printf("memmove OK!\n");
}

void	test_ft_memmove(void) {
	char str1[] = "123456789";

	ft_memmove(str1 + 3, str1, 5);
	assert(strcmp(str1, "123123459") == 0);

	char str2[] = "Hello, World!";
	char dest[20];

	ft_memmove(dest, str2, strlen(str2) + 1);
	assert(strcmp(dest, str2) == 0);

	printf("ft_memmove OK!\n");
	printf("---\n");
}

void	test_strlcpy(void) {
	char dest[10];

	assert(strlcpy(dest, "Hello", sizeof(dest)) == 5);
	assert(strcmp(dest, "Hello") == 0);

	assert(strlcpy(dest, "Hello, World!", 6) == 13);
	assert(strcmp(dest, "Hello") == 0);

	assert(strlcpy(dest, "", sizeof(dest)) == 0);
	assert(strcmp(dest, "") == 0);

	assert(strlcpy(dest, "Test", 0) == 4);

	printf("test_strlcpy OK!\n");
}

void	test_ft_strlcpy(void) {
	char dest[10];

	assert(ft_strlcpy(dest, "Hello", sizeof(dest)) == 5);
	assert(strcmp(dest, "Hello") == 0);

	assert(ft_strlcpy(dest, "Hello, World!", 5) == 13);
	assert(strcmp(dest, "Hello") == 0);

	assert(ft_strlcpy(dest, "", sizeof(dest)) == 0);
	assert(strcmp(dest, "") == 0);

	assert(ft_strlcpy(dest, "Test", 0) == 4);

	printf("test_ft_strlcpy OK!\n");
	printf("---\n");
}
 */
void	test_ft_strlcat(void)
{
	char	dst[20] = "Hello, ";

	printf("ft_strlcat\n");
	printf("%ld\n", ft_strlcat(dst, "World", sizeof(dst)));
	printf("%s\n", dst);
	printf("---\n");
}

void	test_ft_toupper(void)
{
	printf("ft_toupper\n");
	printf("%c", ft_toupper('A'));
	printf("%c", ft_toupper('Z'));
	printf("\n");
}

void	test_ft_tolower(void)
{
	printf("ft_tolower\n");
	printf("%c", ft_tolower('A'));
	printf("%c", ft_tolower('Z'));
	printf("\n");
}

void	test_ft_strchr(void)
{
	printf("ft_strchr\n");
	printf("%s", ft_strchr("hello world", 'w'));
	printf(ft_strchr("hello world", 'W') ? "FIND" : "NULL");
	printf(ft_strchr("hello world", '\0') ? "FIND" : "NULL");
	printf("\n");
}

void	test_ft_strrchr(void)
{
	printf("ft_strrchr\n");
	printf("%s", ft_strrchr("hello world", 'l'));
	printf(ft_strrchr("hello world", 'W') ? "FIND" : "NULL");
	printf(ft_strrchr("hello world", '\0') ? "FIND" : "NULL");
	printf("\n");
}

void	test_ft_strncmp(void)
{
	printf("ft_strncmp\n");
	printf("test 1 %d\n", ft_strncmp("hello world", "hello world", 11));
	printf("test 2 %d\n", ft_strncmp("abc", "abd", 3));
	printf("\n");
}

void	test_ft_memchr(void)
{
	char	str[] = "hello world";

	printf("ft_memchr\n");
	printf("test 1 %s\n", (char *)ft_memchr(str, 'o', 11));
	printf("test 2 %s\n", ft_memchr("abc", 'd', 3) ? "FIND" : "NULL");
	printf("\n");
}

void	test_ft_memcmp(void)
{
	printf("ft_memcmp\n");
	printf("test 1 %d\n", memcmp("abcdef", "abcXef", 5));
	printf("test 2 %d\n", memcmp("abcdef", "abcdef", 6));
	printf("\n");
}

void	test_ft_strstr(void)
{
	printf("ft_strstr\n");
	printf("test 1 %s\n", strstr("TutorialsPoint", "Point"));
	printf("test 2 %s\n", strstr("Welcome to Tutorialspoint", "ials"));
	printf("\n");
}

void	test_ft_calloc(void)
{
	int	*arr;

	printf("ft_calloc\n");
	arr = (int *)ft_calloc(5, sizeof(int));
	if (arr)
	{
		for (int i = 0; i < 5; i++)
			printf("%d ", arr[i]);
	}
	free(arr);
	printf("\n");
}

void	test_ft_atoi(void)
{
	printf("atoi\n");
	printf("test 1 %d\n", atoi("0"));
	printf("test 2 %d\n", atoi("9999999999999"));
	printf("\n");
}

void	test_ft_strdup(void)
{
	char	str[] = "Hello, World!";
	char	*copy;

	printf("ft_strdup\n");
	copy = ft_strdup(str);
	if (copy)
	{
		printf("test 1: %s\n", copy);
		free(copy);
	}
	else
	{
		printf("Memory allocation failed!\n");
	}
	printf("\n");
}

void	test_ft_strjoin(void)
{
	char	*first;
	char	*second;
	char	*third;

	printf("strjoin\n");
	first = ft_strjoin("hello ", "world");
	printf("%s\n", first);
	free(first);
	second = ft_strjoin("hello", "");
	printf("%s\n", second);
	free(second);
	third = ft_strjoin("", "world");
	printf("%s\n", third);
	free(third);
	printf("\n");
}

void	test_ft_substr(void)
{
	char	*result;

	printf("ft_substr\n");
	printf("%s\n", ft_substr("hello world", 0, 5));
	printf("%s\n", ft_substr("hello world", 6, 5));
	printf("%s\n", ft_substr("hello world", 6, 100));
	result = ft_substr("hello world", 12, 5);
	printf("%s\n", result);
	free(result);
	printf("\n");
}

void	test_ft_strtrim(void)
{
	char	*result;

	printf("ft_strtrim\n");
	printf("%s\n", ft_strtrim("   hello world   ", " "));
	result = ft_strtrim("///hello world///", "/");
	printf("%s\n", result);
	free(result);
	result = ft_strtrim("hello world", "xyz");
	printf("%s\n", result);
	free(result);
	result = ft_strtrim("////", "/");
	printf("%s\n", result);
	free(result);
	printf("\n");
}

void	test_ft_split()
{
	char	**result;

	void print_split_result(char **result)
	{
		int		i;
		i = 0;
		while (result[i])
		{
			printf("%s\n", result[i]);
			i++;
		}
	}
	printf("ft_split\n");
	result = ft_split("hello world from C", ' ');
	print_split_result(result);
	for (int i = 0; result[i] != NULL; i++)
        free(result[i]);
    free(result);
	result = ft_split("hello  world  from C", ' ');
    print_split_result(result);
    for (int i = 0; result[i] != NULL; i++)
        free(result[i]);
    free(result);
	result = ft_split("  hello world  ", ' ');
    print_split_result(result);
    for (int i = 0; result[i] != NULL; i++)
        free(result[i]);
    free(result);
	result = ft_split("helloworld", ' ');
    print_split_result(result);
    for (int i = 0; result[i] != NULL; i++)
        free(result[i]);
    free(result);
	result = ft_split("", ' ');
    print_split_result(result);
    for (int i = 0; result[i] != NULL; i++)
        free(result[i]);
    free(result);
	result = ft_split("     ", ' ');
    print_split_result(result);
    for (int i = 0; result[i] != NULL; i++)
        free(result[i]);
    free(result);
	result = ft_split("hello-world-from-C", '-');
    print_split_result(result);
    for (int i = 0; result[i] != NULL; i++)
        free(result[i]);
    free(result);
	printf("\n");
}

int	main(void)
{
	/*     printf("bzero\n");
		char a[] = "goodbye";
		bzero(a, sizeof(a));
		char b[] = "goodbye";
		ft_bzero(b, sizeof(b));
		printf("Expect: - ");
		for (size_t i = 0; i < sizeof(a); i++)
			printf("%d ", a[i]);
		printf("Output: ");
		for (size_t i = 0; i < sizeof(b); i++)
			printf("%d ", b[i]);
		printf("\n");

		test_ft_memcpy();
		test_memmove();
		test_ft_memmove();
		test_strlcpy();
		test_ft_strlcpy(); */
	test_ft_strlcat();
	test_ft_toupper();
	test_ft_tolower();
	test_ft_strchr();
	test_ft_strrchr();
	test_ft_strncmp();
	test_ft_memchr();
	test_ft_memcmp();
	test_ft_strstr();
	test_ft_atoi();
	test_ft_calloc();
	test_ft_strdup();
	test_ft_strjoin();
	test_ft_substr();
	test_ft_strtrim();
	test_ft_split();
	return (0);
}