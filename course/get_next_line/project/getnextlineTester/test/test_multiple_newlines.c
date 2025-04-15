#include <fcntl.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "get_next_line.h"

void generate_multiple_newlines_file()
{
    const char *path = "test/files/multiple_newlines.txt";
    struct stat buffer;

    if (stat(path, &buffer) != 0)
    {

        FILE *file = fopen(path, "w");
        if (file == NULL)
        {
            perror("Failed to create multiple_newlines.txt");
            exit(1);
        }
        fprintf(file, "First Line\n\n\n\nSecond Line\n\nThird Line\n");
        fclose(file);
        printf("Generated: %s\n", path);
    }
}

int main(void)
{
    int fd;
    char *line;
    int i = 0;
    char *expected_lines[] = {
        "First Line\n",
        "\n",
        "\n",
        "\n",
        "Second Line\n",
        "\n",
        "Third Line\n",
        NULL};

    generate_multiple_newlines_file();
    fd = open("test/files/multiple_newlines.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        assert(strcmp(line, expected_lines[i]) == 0);
        free(line);
        i++;
    }
    close(fd);
    assert(expected_lines[i] == NULL);
    printf("\033[0;32mOK\033[0m ");
    return (0);
}
