#ifndef CUB3D_H
# define CUB3D_H
typedef struct s_parse_map
{
    int start;
    int middle;
    int finish;
} t_parse_map;

int parse_map(char *path);

#endif