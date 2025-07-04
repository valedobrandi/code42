/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:40:45 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/04 15:11:12 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER 1024

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
	double					pos_y;
	double					pos_x;
	double				dir_y;
	double				dir_x;
}						t_player;

typedef struct g_entries
{
	char				*path;
	char				*type;
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

typedef struct g_settings
{
	void				*mlx;
	void				*mlx_win;
	void				*img;
	char				*img_data;
	t_player			player;
	t_list				*rgb_texture;
	t_map				*scheme;
	t_data_addr			addr;
}						t_settings;

// parse
int						read_file(char *path, t_list **rgb_texture,
							t_map *schema, t_player *player);
int						parse_texture_rgb(char *line, t_list **rgb_texture);
int						extract_map(char *line, t_map_line *schema);
int						validate_scheme(t_map *schema, t_player *player);
int						validate_rgb(t_list *lst);
int						fill_check(t_map *schema, t_player player);
int						ft_fill_flood(t_map *schema, int height, int width,
							char checker);
int						flood(t_map *schema, int y, int x, char curr);
// helpers
void					free_array(char **strs);
void					free_entries(void *content);
void					free_scheme(t_map *schema);
int						is_space(char str);
int						allocate_scheme(t_map **schema);
int						exit_game(t_settings *settings);
// mlx_hook
int						key_hook(int keycode, t_settings *settings);
// draw
void					init_window(t_settings *settings);
void					draw_pixel(int height, int width, t_settings *st,
							unsigned int color);
void					set_pixels(t_settings *st);
void	castray(t_settings *st);

#endif