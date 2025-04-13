#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../project/get_next_line.h"

int main(void)
{
    int fd;
    char *line;
    int line_count = 0;

    printf("test_only_newlines - ");

    fd = open("test/files/only_newlines.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        assert(strcmp(line, "\n") == 0);
        free(line);
        line_count++;
    }

    close(fd);
    assert(line_count == 5);
    printf("✅");
    return 0;
}
