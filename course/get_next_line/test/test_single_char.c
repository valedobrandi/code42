#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>
#include "../project/get_next_line.h"

void generate_single_char_file()
{
    const char *path = "test/files/single_char.txt";
    struct stat buffer;

    if (stat(path, &buffer) != 0)
    {

        FILE *file = fopen(path, "w");
        if (file == NULL)
        {
            perror("Failed to create single_char.txt");
            exit(1);
        }
        fprintf(file, "A");
        fclose(file);
        printf("Generated: %s\n", path);
    }
}

int main(void)
{
    int fd;
    char *line;
    int result = 0;

    generate_single_char_file();
    fd = open("test/files/single_char.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    line = get_next_line(fd);
    assert(strcmp(line, "A") == 0);
    free(line);
    close(fd);
    printf("\033[0;32mOK\033[0m ");
    return result;
}
