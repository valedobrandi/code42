/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:30:40 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/04 15:32:37 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <mlx.h>
#include <stdlib.h>

int	exit_game(t_settings *settings)
{
	ft_lstclear(&settings->rgb_texture, free_entries);
	free_scheme(settings->scheme);
	if (settings->mlx_win)
		mlx_destroy_window(settings->mlx, settings->mlx_win);
	if (settings->mlx)
		mlx_destroy_display(settings->mlx);
	exit(0);
	return (0);
}
int	set_mlx_hooks(t_settings *settings)
{
	mlx_key_hook(settings->mlx_win, key_hook, settings);
	mlx_hook(settings->mlx_win, 17, 0, exit_game, settings);
	return (0);
}

static int	init_map(t_settings *settings, char **av)
{
	settings->rgb_texture = NULL;
	settings->player.pos_x = -1.0;
	settings->player.pos_y = -1.0;
	settings->player.dir_x = 1.0;
	settings->player.dir_y = 0.0;
	if (allocate_scheme(&settings->scheme))
		return (ft_putendl_fd("MEM: allocate_scheme", 2), 1);
	if (read_file(av[1], &settings->rgb_texture, settings->scheme,
			&settings->player))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_settings	st;

	(void)ac;
	ft_memset(&st, 0, sizeof(t_settings));
	if (init_map(&st, av))
		exit_game(&st);
	st.mlx = mlx_init();
	st.mlx_win = mlx_new_window(st.mlx,
			st.scheme->map[0].length * 20, st.scheme->height * 20,
			"cub3d");
	st.img = mlx_new_image(st.mlx, 800, 600);
	st.img_data = mlx_get_data_addr(st.img, &st.addr.bpp, &st.addr.line_len, &st.addr.endian);
	set_mlx_hooks(&st);
	init_window(&st);
	mlx_loop(st.mlx);
	return (0);
}
