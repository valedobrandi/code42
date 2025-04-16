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
	for (int i = 0; i < 1000; i++)
	{
		fprintf(file, "A\n");
	}
	fclose(file);
}

int	main(void)
{
	int			fd;
	char		*line;
	const char	*expected = "A\n";
	int			line_count;

	line_count = 0;
	generate_file();
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		assert(strcmp(line, expected) == 0);
		free(line);
		line_count++;
	}
	close(fd);
	assert(line_count == 1000); // Expecting 1000 lines of "A\n"
	printf("\033[0;32mOK\033[0m ");
	return (0);
}
