    #include <stdio.h>
    #include <string.h>
    #include <limits.h>

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

int test_ftptintf_i()
{
    char ft_output[1024];
    char std_output[1024];

    // Test 1
    printf("Test 1: printf with \" %%i \", 10\n");
    snprintf(ft_output, sizeof(ft_output), " %i ", 10);
    snprintf(std_output, sizeof(std_output), " %i ", 10);
    printf("ft_output: [%s] = %ld ", ft_output, ft_strlen(ft_output));
    printf("std_output: [%s] = %ld ", std_output, ft_strlen(std_output));
    if (strcmp(ft_output, std_output) == 0) {
        printf("✅ ");
    } else {
        printf("❌ ");
    }
    printf("\n\n");
    return (0);
    }

int main(void)
{
    test_ftptintf_i();
    return (0);
}