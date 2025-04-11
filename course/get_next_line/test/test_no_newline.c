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

    printf("==== No Newline at EOF Test ====\n");

    fd = open("test/files/test_nl_end.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    printf("Reading file with no newline at EOF:\n");
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s", line_number, line);
        if (strchr(line, '\n') == NULL)
            printf(" ✅ ");
        else
            printf("\n");
        free(line);
        line_number++;
    }

    close(fd);

    printf("Test completed!\n");
    return result;
}
