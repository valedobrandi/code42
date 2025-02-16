#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096
#define DICT_SIZE 41

typedef struct dict_entry
{
    char *value;
    char *name;
} new_dict_entry;

char    buffer[BUFFER_SIZE];
new_dict_entry    *dict = NULL;

char *ft_strncpy(char *dest, char *src, int n)
{
    int index;

    index = 0;
    while (src[index] != '\0' && index < n )
    {
        dest[index] = src[index];
        index++;
    }
        dest[index] = '\0';
    return (dest);
}

int ft_strlen(char *str)
{
    int index;

    index = 0;
    while (str[index] != '\0') 
        index ++;
    return (index); 
}

int    ft_strchr(char *str) 
{
    int index;

    index = 0;
    while (str[index] != '\0') {
        if (str[index] == ':') {
            return (index);
        }
        index++;
    }

    return (-1); 
}
char *trim(char *src)
{
    int flag;
    char *dest;
    char *dest_start;  
    
    dest = (char *)malloc(ft_strlen(src) + 1); 
    dest_start = dest;
    if (!dest)
        return NULL;  
    while (*src != '\0')
    {
        if (*src == ' ')  
        {
            if (flag == 1)
            {
                *dest = '-';
                dest++;
                flag = 0;
            }
        }
        else
        {
            *dest = *src;
            dest++;
            flag = 1;
            if (*src == ':')
                flag = 0;
        }
        src++;
    }
    *dest = '\0';
    return (dest_start);
}

char *replace_trim(char *src)
{
    char *dest; 
    char *dest_start;  
    
    dest = (char *)malloc(ft_strlen(src) + 1); 
    dest_start = dest;
    if (!dest)
        return NULL;  
    while (*src != '\0')
    {
        if (*src == '-')  
            *dest = ' ';
        else
            *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return (dest_start);
}


int get_value(char *line, int *index) 
{
    int     divider;
    char *value;

    divider = ft_strchr(line);
    if (divider == -1)
        return (0); 
    dict[*index].value = (char *)malloc(divider + 1);
    if (dict[*index].value == NULL)
        return (1);
    ft_strncpy(dict[*index].value, line, divider);
    return (0);
}

int get_name(char *line, int *index) 
{
    int     divider;
    int     length;

    divider = ft_strchr(line);
    if (divider == -1)
        return (0); 
    length = ft_strlen(line) - divider;

    dict[*index].name = (char *)malloc(length + 1);
    if (dict[*index].name == NULL)
        return (1);
    ft_strncpy(dict[*index].name, &line[divider + 1], length);
    return (0);
}

char *copy_line(int *index, int *count)
{
    char *str; 
    char *trimmed;
    char *replaced;

    str = (char *)malloc(*count + 1);
    if (str == NULL)
        return NULL;
    ft_strncpy(str, &buffer[*index - *count], *count);
    trimmed = trim(str);
    free(str);
    if (trimmed == NULL)
        return NULL;
    replaced = replace_trim(trimmed);
    free(trimmed);
    if (replaced == NULL)
        return NULL;

    return replaced;
}

int    get_line(int is_default)
{
    char    *str;
    int     count;
    int     index;
    int     dict_index;

    index = 0;
    count = 0;
    dict_index = 0;
    while (buffer[index] != '\0')
    {  
        if (buffer[index] == '\n')
        {
            str = copy_line(&index, &count);
            if (str == NULL)
                return 1;
            get_value(str, &dict_index);
            if (is_default)
                get_name(str, &dict_index);
            free(str);
            count = 0;
            dict_index++;
        }
        else
            count++;
        index++;
   }
    return (0);
} 

int     buffer_dictionary()
{   
   dict = (new_dict_entry *)malloc(DICT_SIZE * sizeof(new_dict_entry));
   if (dict == NULL) return (1);
   return (0);
}

int     open_file(char *filename)
{
    int     fd;
    int     bytes_read;

    fd = open(filename, O_RDONLY);
    if (fd == -1) 
        return (1);    
    bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
    if (bytes_read > 0)
        buffer[bytes_read] = '\0';
    if (bytes_read == -1)
    {
        close(fd);
        return (1);
    }
    close(fd);
    return (buffer_dictionary());    
}

int main(int argc, char **argv)
{
    if (open_file("numbers.dict"))
        return (0);
    get_line(1);

    return (0);
}