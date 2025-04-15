#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>
#include "get_next_line.h"

void generate_multiple_lines_file()
{
    const char *path = "test/files/multiple_lines.txt";
    struct stat buffer;

    if (stat(path, &buffer) != 0)
    {
        FILE *file = fopen(path, "w");
        if (file == NULL)
        {
            perror("Failed to create multiple_lines.txt");
            exit(1);
        }
        fprintf(file, "Line 1\nLine 2\nLine 3\nLine 4\n");
        fclose(file);
        printf("Generated: %s\n", path);
    }
}

int main(void)
{
    int fd;
    char *line;
    const char *expected[] = {
        "Line 1\n",
        "Line 2\n",
        "Line 3\n",
        "Line 4\n"};
    generate_multiple_lines_file();
    int index = 0;
    fd = open("test/files/multiple_lines.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        assert(strcmp(line, expected[index]) == 0);
        free(line);
        index++;
    }
    close(fd);
    assert(index == 4);
    printf("\033[0;32mOK\033[0m ");
    return 0;
}
