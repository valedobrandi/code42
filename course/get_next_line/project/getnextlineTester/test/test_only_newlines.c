#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>
#include "get_next_line.h"

void generate_only_newlines_file()
{
    const char *path = "test/files/only_newlines.txt";
    struct stat buffer;

    if (stat(path, &buffer) != 0)
    {

        FILE *file = fopen(path, "w");
        if (file == NULL)
        {
            perror("Failed to create only_newlines.txt");
            exit(1);
        }
        // Writing 5 newlines to the file
        for (int i = 0; i < 5; i++) {
            fprintf(file, "\n");
        }
        fclose(file);
        printf("Generated: %s\n", path);
    }
}

int main(void)
{
    int fd;
    char *line;
    int line_count = 0;
    const char *expected = "\n";

    generate_only_newlines_file();
    fd = open("test/files/only_newlines.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        assert(strcmp(line, expected) == 0);
        free(line);
        line_count++;
    }

    close(fd);
    assert(line_count == 5);
    printf("\033[0;32mOK \033[0m");
    return 0;
}

