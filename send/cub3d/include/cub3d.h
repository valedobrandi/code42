/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:40:45 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/28 11:55:37 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER 1024

# define MINIMAP_SCALE 3
# define TILE_SIZE 4

# define WIDTH 1000
# define HEIGHT 600

# define PI 3.1415926535
# define NUM_RAYS 360

# define MOVE_SPEED 0.02
# define ROTATE_SPEED 0.01

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

# include <stdio.h>

typedef struct s_list	t_list;

typedef struct s_raycast
{
	double				ray_angle;
	double				wall_distance;
	int					wall_start;
	int					wall_end;
	int					tex_x;
	double				tex_step;
	double				tex_pos;
}						t_raycast;

typedef struct s_cast_dda
{
	double				ray_dx;
	double				ray_dy;
	double				ray_x;
	double				ray_y;
	int					map_x;
	int					map_y;
	int					step_x;
	int					step_y;
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				raw_distance;
	double				wall_x;
}						t_cast_dda;

typedef struct s_dda_result
{
	int					wall_direction;
	double				fisheye;
	int					hit_wall;
	int					wall_side;
	double				wall_x;
	int					map_x;
	int					map_y;
	double				hit_x;
	double				hit_y;
	double				raw_distance;
}						t_dda_result;

typedef struct s_data_addr
{
	int					bpp;
	int					line_len;
	int					endian;
}						t_data_addr;

typedef struct s_player
{
	double				py;
	double				px;
	double				pdy;
	double				pdx;
	double				pa;
}						t_player;

typedef struct s_entries
{
	char				*type;
	char				*path;
}						t_entries;

typedef struct s_map_line
{
	char				*path;
	int					length;
}						t_map_line;

typedef struct s_map
{
	t_map_line			*map;
	int					height;
}						t_map;

typedef struct s_keys
{
	int					up;
	int					down;
	int					left;
	int					rigth;
}						t_keys;

typedef struct s_mem_stack
{
	void				*ptr[20];
	int					top;
}						t_mem_stack;

typedef struct s_image_addr
{
	char				*data;
	int					bpp;
	int					line_len;
	int					endian;
	int					width;
	int					height;
}						t_image_addr;

typedef struct s_texture
{
	t_image_addr		north;
	t_image_addr		south;
	t_image_addr		east;
	t_image_addr		west;
}						t_texture;

typedef struct s_settings
{
	void				*mlx;
	void				*mlx_win;
	void				*img;
	char				*img_data;
	void				*texture_width;
	void				*texture_heigth;
	int					rbg_c[3];
	int					rbg_f[3];
	t_mem_stack			mem_stack;
	t_texture			mlx_texture;
	t_player			player;
	t_list				*rgb_texture;
	t_map				*scheme;
	t_data_addr			addr;
	t_keys				keys;
}						t_settings;

typedef struct s_render
{
	t_dda_result		ray;
	t_image_addr		addr;
	t_raycast			cast;
	int					i;
	double				pixel_ratio;
	double				centered_ratio;
	double				angle_offset;
}						t_render;

/* === Parse === */
int						read_file(char *path, t_settings *st);
int						parse_texture_rgb(char *line, t_list **rgb_texture);
int						extract_map(char *line, t_map_line *schema);
int						validate_scheme(t_map *schema, t_settings *st);
int						validate_rgb(t_list *lst, t_settings *st);
int						fill_check(t_map *schema, t_player player);
int						ft_fill_flood(t_map *schema, int height, int width,
							char checker);
int						flood(t_map *schema, int y, int x, char curr);
int						validate_texture(t_list *lst);

/* === Helpers === */
void					free_array(char **strs);
void					free_entries(void *content);
void					free_scheme(t_map *schema);
int						is_space(char str);
int						allocate_scheme(t_map **schema);
int						exit_game(t_settings *settings);
void					free_all(t_mem_stack *mem, void *mlx);
void					*track_alloc(t_mem_stack *mem, void *ptr);

/* === mlx_hook === */
int						key_hook(int keycode, t_settings *settings);
int						set_mlx_hooks(t_settings *st);
void					backward(t_settings *st);
void					forward(t_settings *st);
void					rotate_right(t_settings *st);
void					rotate_left(t_settings *st);
int						key_press(int keycode, t_settings *st);
int						key_release(int keycode, t_settings *st);
int						key_update(t_settings *st);
void					initializer_mlx_image(t_settings *st);

/* === Draw === */
void					draw_map(t_settings *settings);
void					draw_pixel(int height, int width, t_settings *st,
							unsigned int color);
void					set_pixels(t_settings *st);
void					drawrays3d(t_settings *st);
void					raytracer_render(t_settings **st);
void					next_grid_line(t_cast_dda *t);
void					next_grid_boundary(t_cast_dda *t);
void					ray_travel_distance(int *hit, int *side, t_cast_dda *t,
							t_settings *st);
void					texture_mapping(int side, t_dda_result *result,
							t_cast_dda *t);
t_dda_result			cast_dda_ray(t_settings *st, double ray_angle);
void					draw_minimap(t_settings *st);
void					draw_minimap_tile(int map_y, int map_x, t_settings *st,
							unsigned int color);
void					load_texture_addr(int dir, t_image_addr *addr,
							t_settings **st);
void					wall_start_end(t_raycast *cast, double dist, int i,
							t_settings **st);
void					load_texture(t_raycast *cast, t_dda_result ray,
							t_image_addr addr);
void					render(t_raycast *cast, t_image_addr addr,
							t_settings **st, int i);

#endif
