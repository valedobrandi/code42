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
	fprintf(file,
		"01010101010101010101010101010101010101010101010101010101010101010101010101");
	fclose(file);
}

int	main(void)
{
	int			fd;
	char		*line;
	const char	*expected[] = {"01010101010101010101010101010101010101010101010101010101010101010101010101"};
	int			index;

	generate_file();
	index = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		assert(strcmp(line, expected[index]) == 0);
		free(line);
		index++;
	}
	close(fd);
	assert(index == 1);
	printf("\033[0;32mOK\033[0m ");
	return (0);
}
