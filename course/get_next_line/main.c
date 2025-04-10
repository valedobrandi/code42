#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int     fd;

	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
		return (0);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));;
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
