#include "get_next_line.h"
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

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
	for (int i = 0; i < 2000; i++)
	{
		fprintf(file, "A");
	}
	fclose(file);
}

int	main(void)
{
	int		fd;
	char	*line;
	char	expected[2000];
	int		result;

	result = 0;
	generate_file();
    expected[2000] = '\0';
	memset(expected, 'A', 2000);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	line = get_next_line(fd);
	assert(strcmp(line, expected) == 0);
	free(line);
	close(fd);
	printf("\033[0;32mOK\033[0m ");
	return (result);
}
