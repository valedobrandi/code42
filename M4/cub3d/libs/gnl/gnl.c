#include "include/get_next_line.h"

char *read_line(int fd, char *stash) {
    char buffer[BUFFER_SIZE + 1];
    int bytes_reader = 1;

    while (!ft_strchr(stash, '\n') && bytes_reader > 0)
    {
        bytes_reader = read(fd, buffer, BUFFER_SIZE);
        if (bytes_reader == -1)
            return NULL;
        buffer[bytes_reader] = '\0';
        stash = ft_strjoin(stash, buffer);
    }
	return stash;
}

char *extract_line(char *stash) {
	if (!stash || !*stash)
		return NULL;
	int i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	char *line = ft_substr(stash, 0, stash[i] == '\n' ? i + 1 : i);
	return line;
}

char *clean_stash(char *stash) {
	char *newline = ft_strchr(stash, '\n');
	if (!newline)
		return NULL;
	char *new_stash = ft_strdup(newline + 1);
	if (!new_stash)
		return NULL;
	free(stash);
	return new_stash;
}

char *get_next_line(int fd) {
    static char *stash;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    stash = read_line(fd, stash);
	if (!stash)
		return NULL;

	line = extract_line(stash);
	stash = clean_stash(stash);

	return line;
}