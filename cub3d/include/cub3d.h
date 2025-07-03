#ifndef CUB3D_H
#define CUB3D_h

#define BUFFER 1024
typedef struct s_list	t_list;

typedef struct g_player
{
    int cord_y;
    int cord_x;
} t_player;


typedef struct g_entries
{
    char *path;
    char *type;
} t_entries;

typedef struct g_map_line
{
    char *path;
    int length;
} t_map_line;

typedef struct g_map
{
    t_map_line *map;
    int height;
} t_map;

// parse
int read_file(char *path, t_list **rgb_texture, t_map *schema);
int parse_texture_rgb(char *line, t_list **rgb_texture);
int extract_map(char *line, t_map_line *schema);
int validate_schema(t_map *schema, t_player *player);
int validate_rgb(t_list *lst);
// helpers
void free_array(char **strs);
void free_entries(void *content);
void free_schema(t_map *schema);
int is_space(char str);

#endif