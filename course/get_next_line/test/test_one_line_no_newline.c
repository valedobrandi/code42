#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>
#include "../project/get_next_line.h"

void generate_one_line_no_newline_file()
{
    const char *path = "test/files/one_line_no_newline.txt";
    struct stat buffer;

    if (stat(path, &buffer) != 0)
    {

        FILE *file = fopen(path, "w");
        if (file == NULL)
        {
            perror("Failed to create one_line_no_newline.txt");
            exit(1);
        }
        fprintf(file, "HelloWorld");
        fclose(file);
        printf("Generated: %s\n", path);
    }
}

int main(void)
{
    int fd;
    char *line;
    char *result = "HelloWorld";

    generate_one_line_no_newline_file();
    fd = open("test/files/one_line_no_newline.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    line = get_next_line(fd);
    assert(strcmp(line, result) == 0);
    assert(strchr(line, '\n') == NULL);
    free(line);
    printf("\033[0;32mTest OK - \033[0m");
    close(fd);
    return 0;
}
