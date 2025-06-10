#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SZE
# define BUFFER_SIZE 42
#endif

int ft_strlen(char *s);
char *ft_strchr(char *s, char c);
char *ft_strdup(char *s1);
char *ft_strjoin(char *s1, char *s2);
char *ft_substr(char *s, int start, int len);
char *get_next_line(int fd);
#endif