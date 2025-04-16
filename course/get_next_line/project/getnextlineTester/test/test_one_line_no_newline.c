#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>
#include "get_next_line.h"

const char	*path = "test/files/test_file.txt";
void	generate_file(void)
{
	FILE	*file;

	remove(path);
	file = fopen(path, "w");
	if (file == NULL)
	{
		perror("Failed to create file");
		exit(EXIT_FAILURE);
	}
	fprintf(file, "HelloWorld");
	fclose(file);
}
int main(void)
{
    int fd;
    char *line;
    char *result = "HelloWorld";

    generate_file();
    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    line = get_next_line(fd);
    assert(strcmp(line, result) == 0);
    assert(strchr(line, '\n') == NULL);
    free(line);
    printf("\033[0;32mOK \033[0m");
    close(fd);
    return 0;
}
