#include "get_next_line.h"
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const char *path = "test/files/main.txt";

int main(void)
{
	int fd;
	char *line;

	// Open the file for reading
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	// Test get_next_line function with multiple lines
	line = get_next_line(fd);
	assert(strcmp(line, "9876543210987654321098765432109876543210\n") == 0);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	assert(strcmp(line, "01234567890123456789012345678901234567890\n") == 0);
	free(line);
	line = get_next_line(fd);
	assert(strcmp(line, "987654321098765432109876543210987654321098\n") == 0);
	free(line);
	line = get_next_line(fd);
	assert(strcmp(line, "01234567890123456789012345678901234567890\n") == 0);
	free(line);
	line = get_next_line(fd);
	assert(strcmp(line, "9876543210987654321098765432109876543210") == 0);
	free(line);
	// Final read: it should return NULL indicating EOF
	line = get_next_line(fd);
	assert(line == NULL); // This should return NULL when EOF is reached
	// Close the file descriptor
	close(fd);
	printf("\033[0;32mOK\033[0m ");
	return (0);
}
