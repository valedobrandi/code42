#include "get_next_line.h"
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

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
		fprintf(file, "This is a line in the large file.\n");
	}
	fclose(file);
}

int	main(void)
{
	int			fd;
	char		*line;
	int			result;
	int			line_number;
	const char	*expected = "This is a line in the large file.\n";

	result = 0;
	line_number = 1;
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
		line_number++;
	}
	close(fd);
	assert(line_number - 1 == 1000);
	printf("\033[0;32mOK\033[0m ");
	return (result);
}
