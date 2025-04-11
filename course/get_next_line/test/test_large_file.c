#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../project/get_next_line.h"

int main(void)
{
    int fd;
    char *line;
    int line_number = 1;
    int result = 0;

    printf("==== Large File Test ====\n");

    fd = open("test/files/large_file.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
		printf("Line %d: %s", line_number, line);
        free(line);
        line_number++;
    }

    close(fd);
    printf("Test completed with %d lines!\n", line_number - 1);
    return result;
}
