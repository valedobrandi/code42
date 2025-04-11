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

    printf("==== Normal File with Multiple Lines Test ====\n");

    fd = open("test/files/multiple_lines.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    printf("Reading file with multiple lines:\n");
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("OUTPUT: line %d: %s", line_number, line);
        free(line);
        line_number++;
    }

    close(fd);
    printf("Test completed!\n");
    return result;
}
