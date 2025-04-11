#include "../project/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		result;

	result = 0;
	printf("==== Multiple Newlines Test ====\n");
	fd = open("test/files/multiple_newlines.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		if (line[0] == '\0')
			printf("✅ ");
		else
			printf("❌ Expected empty line but got: \"%s\"\n", line);
		free(line);
	}
	close(fd);
	printf("Test completed!\n");
	return (result);
}
