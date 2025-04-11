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

    printf("==== File with Only Newlines Test ====\n");

    fd = open("test/files/only_newlines.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line: \"%s\"\n", line);
        free(line);
    }

    close(fd);
    printf("Test completed!\n");
    return result;
}
