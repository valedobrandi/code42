#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*read_to_stash(int fd, char *stash);
char	*extract_line(char *stash);
char	*update_stash(char *stash);

#endif

// get_next_line.c
#include "get_next_line.h"

// Extract the line from stash (up to and including \n or \0)
char *extract_line(char *stash)
{
    int i = 0;
    char *line;

    // Handle empty stash
    if (!stash || !stash[0])
        return (NULL);

    // Find length of line (up to and including \n)
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;  // Include the newline

    // Allocate memory for line (+1 for null terminator)
    line = malloc(sizeof(char) * (i + 1));
    if (!line)
        return (NULL);

    // Copy content from stash to line
    i = 0;
    while (stash[i] && stash[i] != '\n')
    {
        line[i] = stash[i];
        i++;
    }
    if (stash[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';

    return (line);
}

// Update stash to contain only what comes after the first line
char *update_stash(char *stash)
{
    int i = 0;
    int j = 0;
    char *new_stash;

    // Find end of first line
    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i])  // If no newline found, we've read everything
    {
        free(stash);
        return (NULL);
    }
    i++;  // Skip the newline

    // Allocate memory for the remaining content
    new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
    if (!new_stash)
    {
        free(stash);
        return (NULL);
    }

    // Copy remaining content to new stash
    while (stash[i + j])
    {
        new_stash[j] = stash[i + j];
        j++;
    }
    new_stash[j] = '\0';
    free(stash);

    return (new_stash);
}

// Read from file and append to stash until newline is found or EOF
char *read_to_stash(int fd, char *stash)
{
    char *buffer;
    int bytes_read;

    // Allocate buffer
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);

    // Read file until newline is found or EOF
    bytes_read = 1;  // Initial value to enter the loop
    while (bytes_read > 0 && !ft_strchr(stash, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)  // Error handling
        {
            free(buffer);
            free(stash);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        stash = ft_strjoin(stash, buffer);
        if (!stash)
        {
            free(buffer);
            return (NULL);
        }
    }
    free(buffer);

    return (stash);
}

// Main function
char *get_next_line(int fd)
{
    static char *stash;  // Saves buffer content between calls
    char *line;

    // Input validation
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    // Read from file and append to stash
    stash = read_to_stash(fd, stash);
    if (!stash)
        return (NULL);

    // Extract line from stash
    line = extract_line(stash);

    // Update stash for next call
    stash = update_stash(stash);

    return (line);
}

// get_next_line_utils.c
#include "get_next_line.h"

// Get string length
size_t ft_strlen(char *s)
{
    size_t len = 0;

    if (!s)
        return (0);
    while (s[len])
        len++;
    return (len);
}

// Find character in string
char *ft_strchr(char *s, int c)
{
    if (!s)
        return (NULL);
    while (*s)
    {
        if (*s == (char)c)
            return (s);
        s++;
    }
    if (*s == (char)c)
        return (s);
    return (NULL);
}

// Join two strings, freeing the first one
char *ft_strjoin(char *s1, char *s2)
{
    char *result;
    size_t i = 0;
    size_t j = 0;

    if (!s1)  // If s1 is NULL, create an empty string
    {
        s1 = malloc(sizeof(char));
        if (!s1)
            return (NULL);
        s1[0] = '\0';
    }
    // Allocate memory for the result
    result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!result)
    {
        free(s1);
        return (NULL);
    }
    // Copy s1 into result
    while (s1[i])
    {
        result[i] = s1[i];
        i++;
    }
    // Copy s2 after s1
    while (s2[j])
        result[i++] = s2[j++];
    result[i] = '\0';
    free(s1);  // Free old s1
    return (result);
}
