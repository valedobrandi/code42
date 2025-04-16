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
	fprintf(file, "\n\n\n"); // Multiple newlines
	fclose(file);
}

int	main(void)
{
	int			fd;
	char		*line;
	const char	*expected[] = {"\n", "\n", "\n"};
	int			line_number;

	line_number = 0;
	generate_file();
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		assert(strcmp(line, expected[line_number]) == 0);
		free(line);
		line_number++;
	}
	close(fd);
	assert(line_number == 3);
	printf("\033[0;32mOK\033[0m ");
	return (0);
}
