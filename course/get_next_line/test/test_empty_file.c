#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../project/get_next_line.h"

int main(void)
{
    int fd;
    char *line;
    int result = 0;

    printf("==== Empty File Test ====\n");

    fd = open("test/files/empty.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    line = get_next_line(fd);
    if (line == NULL)
        printf("✅ ");
    else
    {
        printf("❌ Expected NULL but got: \"%s\"\n", line);
        free(line);
        result = 1;
    }

    close(fd);

    printf(result == 0 ? "Test passed!\n" : "Test failed!\n");
    return result;
}
