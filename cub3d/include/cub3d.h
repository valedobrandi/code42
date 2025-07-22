/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:40:45 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/22 14:45:34 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER 1024

# define TILE_SIZE 40

# define PI 3.14159265358979323846
# define FFOV (60.0 * (PI / 180.0))
# define HFOV FFOV / 2.0
# define NUM_RAYS 360

# define MOVE_SPEED 0.2
# define ROTATE_SPEED 0.02

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

typedef struct s_list	t_list;

typedef struct g_data_addr
{
	int					bpp;
	int					line_len;
	int					endian;
}						t_data_addr;

typedef struct g_player
{
	double				py;
	double				px;
	double				pdy;
	double				pdx;
	double				pa;
}						t_player;

typedef struct g_entries
{
	char				*type;
	char				*path;
}						t_entries;

typedef struct g_map_line
{
	char				*path;
	int					length;
}						t_map_line;

typedef struct g_map
{
	t_map_line			*map;
	int					height;
}						t_map;

typedef struct g_keys
{
	int					up;
	int					down;
	int					left;
	int					rigth;
}						t_keys;

typedef struct g_texture
{
	void				*north_wall;
	void				*south_wall;
	void				*east_wall;
	void				*west_wall;
}						t_texture;

typedef struct s_mem_stack
{
	void				*ptr[20];
	int					top;
}						t_mem_stack;

typedef struct g_settings
{
	void				*mlx;
	void				*mlx_win;
	void				*img;
	char				*img_data;
	void				*texture_width;
	void				*texture_heigth;
	t_mem_stack			mem_stack;
	t_texture			mlx_texture;
	t_player			player;
	t_list				*rgb_texture;
	t_map				*scheme;
	t_data_addr			addr;
	t_keys				keys;
}						t_settings;

// parse
int						read_file(char *path, t_list **rgb_texture,
							t_map *scheme, t_player *player);
int						parse_texture_rgb(char *line, t_list **rgb_texture);
int						extract_map(char *line, t_map_line *schema);
int						validate_scheme(t_map *schema, t_player *player);
int						validate_rgb(t_list *lst);
int						fill_check(t_map *schema, t_player player);
int						ft_fill_flood(t_map *schema, int height, int width,
							char checker);
int						flood(t_map *schema, int y, int x, char curr);
int						validate_texture(t_list *lst);

// helpers
void					free_array(char **strs);
void					free_entries(void *content);
void					free_scheme(t_map *schema);
int						is_space(char str);
int						allocate_scheme(t_map **schema);
int						exit_game(t_settings *settings);
void					free_all(t_mem_stack *mem, void *mlx);
void					*track_alloc(t_mem_stack *mem, void *ptr);

// mlx_hook
int						key_hook(int keycode, t_settings *settings);
int						set_mlx_hooks(t_settings *settings);
void					backward(t_settings *st);
void					forward(t_settings *st);
void					rotate_rigth(t_settings *st);
void					rotate_left(t_settings *st);
int						set_mlx_hooks(t_settings *st);
int						key_press(int keycode, t_settings *st);
int						key_release(int keycode, t_settings *st);
int						key_update(t_settings *st);
void					initializer_mlx_image(t_settings *st);

// draw
void					init_window(t_settings *settings);
void					draw_pixel(int height, int width, t_settings *st,
							unsigned int color);
void					set_pixels(t_settings *st);
void					drawrays3d(t_settings *st);
void					render3d(t_settings **st);

#endif