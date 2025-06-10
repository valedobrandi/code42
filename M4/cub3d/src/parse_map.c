#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include "cub3D.h"
#include <stdio.h>

int parse_map(char *path)
{
    int fd = open(path, O_RDONLY);
    t_parse_map t = {0};
    char *next_line;

    if (fd == -1)
        return (perror("open"), 1);

    t.start = -1;
    t.middle = -1;
    t.finish = -1;

    int count = 0;
    while ((next_line = get_next_line(fd)) != NULL)
    {
        int i = 0;
        while (next_line[i])
        {

            if (next_line[i] == ' ' || next_line[i] == '\n')
            {
                printf("%c", next_line[i]);
                t.start = -1, t.middle = -1, t.finish = -1;
            }
            else if (next_line[i] == '0')
            {
                printf("%c", next_line[i]);
                t.middle = i;
                if (t.middle > t.start)
                    return (printf("Error"), 1);
            }
            else if (next_line[i] == '1')
            {
                printf("%c", next_line[i]);
                if (next_line[i] == '0')
                    if (t.start == -1)
                        t.start = i;
                    else
                        t.finish = i;
            }
            i++;
        }
        count++;
        free(next_line);
    }
    close(fd);
    printf("SUCESS");
    return (0);
}
