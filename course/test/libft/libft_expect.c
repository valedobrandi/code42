
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <ctype.h>

void test_strlcat() {
    char dst[20] = "Hello, ";

    printf("ft_strlcat\n");
    printf("%ld\n", strlcat(dst, "World", sizeof(dst)));
    printf("%s\n", dst);       
    printf("---\n");
}

void test_toupper() {
    printf("ft_toupper\n");
    printf("A");
    printf("Z");       
    printf("\n");
}

void test_ft_tolower() {
    printf("ft_tolower\n");
    printf("a");
    printf("z");       
    printf("\n");
}

void test_ft_strchr() {
    printf("strchr\n");
    printf("%s", strchr("hello world", 'w'));
    printf(strchr("hello world", 'W') ? "FIND" : "NULL");
    printf(strchr("hello world", '\0') ? "FIND" : "NULL");       
    printf("\n");
}

void test_ft_strrchr() {
    printf("strrchr\n");
    printf("%s", strrchr("hello world", 'l'));
    printf(strrchr("hello world", 'W') ? "FIND" : "NULL");
    printf(strrchr("hello world", '\0') ? "FIND" : "NULL");       
    printf("\n");
}

void test_ft_strncmp() {
    printf("strcmp\n");
    printf("test 1 %d\n", strncmp("hello world", "hello world", 11));
    printf("test 2 %d\n", strncmp("abc", "abd", 3));     
    printf("\n");
}

void test_ft_memchr() {
    printf("memchr\n");
    char str[] = "hello world";
    printf("test 1 %s\n", (char *)memchr(str, 'o', 11));
    printf("test 2 %s\n", memchr("abc", 'd', 3) ? "FIND" : "NULL");   
    printf("\n");
}

void test_ft_memcmp() {
    printf("memcmp\n");
    printf("test 1 %d\n", memcmp("abcdef", "abcXef", 5));
    printf("test 2 %d\n", memcmp("abcdef", "abcdef", 6));   
    printf("\n");
}

void test_ft_strstr() {
    printf("strstr\n");
    printf("test 1 %s\n", strstr("TutorialsPoint", "Point"));
    printf("test 2 %s\n", strstr("Welcome to Tutorialspoint", "ials"));   
    printf("\n");
}

void test_ft_calloc() {
    printf("calloc\n");
    int *arr = (int *)calloc(5, sizeof(int));
    if (arr)
    {
        for (int i = 0; i < 5; i++)
            printf("%d ", arr[i]); 
    }
    free(arr);   
    printf("\n");
}

void test_ft_atoi() {
    printf("atoi\n");
    printf("test 1 %d\n", atoi("0"));
    printf("test 2 %d\n", atoi("9999999999999"));   
    printf("\n");
}

void test_ft_strdup() {
    printf("strdup\n");
    char str[] = "Hello, World!";
    char *copy = strdup(str);
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

int main(void)
{
    test_strlcat();
    test_toupper();
    test_ft_tolower();
    test_ft_strchr();
    test_ft_strrchr();
    test_ft_strncmp();
    test_ft_memchr();
    test_ft_memcmp();
    test_ft_strstr();
    test_ft_calloc();
    test_ft_atoi();
    test_ft_strdup();
    return (0);
}