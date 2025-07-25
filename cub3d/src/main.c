/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:30:40 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/25 12:18:21 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <mlx.h>
#include <stdlib.h>
#include <math.h>

int	exit_game(t_settings *st)
{
	ft_lstclear(&st->rgb_texture, free_entries);
	free_scheme(st->scheme);
	free_all(&st->mem_stack, st->mlx);
    if (st->img) mlx_destroy_image(st->mlx, st->img);
	if (st->mlx_win)
		mlx_destroy_window(st->mlx, st->mlx_win);
	if (st->mlx)
	{
		mlx_destroy_display(st->mlx);
		free(st->mlx);
	}
	exit(0);
	return (0);
}

static int	init_map(t_settings *st, char **av)
{
	st->rgb_texture = NULL;
    st->player.pa = 0.0;
	st->player.px = -1.0;
	st->player.py = -1.0;
	st->player.pdx = cos(st->player.pa) * MOVE_SPEED;
	st->player.pdy = sin(st->player.pa) * MOVE_SPEED;
	if (allocate_scheme(&st->scheme))
		return (ft_putendl_fd("MEM: allocate_scheme", 2), 1);
	if (read_file(av[1], st))
		return (1);
	st->player.py = (st->player.py * TILE_SIZE) + TILE_SIZE / 2;
	st->player.px = (st->player.px * TILE_SIZE) + TILE_SIZE / 2;
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
	st.mlx_win = mlx_new_window(st.mlx, WIDTH, HEIGHT, "cub3d");
	st.img = mlx_new_image(st.mlx, WIDTH, HEIGHT);
	initializer_mlx_image(&st);
	st.img_data = mlx_get_data_addr(st.img, &st.addr.bpp, &st.addr.line_len, &st.addr.endian);
	set_mlx_hooks(&st);
	init_window(&st);
	mlx_loop(st.mlx);
	return (0);
}
