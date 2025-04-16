#include <fcntl.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	fprintf(file, "Line 1\n");
	fprintf(file, "Line 2\n");
	fprintf(file, "Line 3");
	fclose(file);
}

int main(void)
{
    int fd;
    char *line;
    const char *expected[] = {
        "Line 1\n",
        "Line 2\n",
        "Line 3"  // No newline here
    };
    int line_number = 0;

    generate_file();
    fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        assert(strcmp(line, expected[line_number]) == 0);
        free(line);
        line_number++;
    }
    close(fd);
    assert(line_number == 3);  // Expecting 3 lines
    printf("\033[0;32mOK\033[0m ");
    return 0;
}
