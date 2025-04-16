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
	fprintf(file, "Line 1\nLine 2\nLine 3\nLine 4\n");
	fclose(file);
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
	generate_file();
    int index = 0;
    fd = open(path, O_RDONLY);
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
