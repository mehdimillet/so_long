/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:24:42 by memillet          #+#    #+#             */
/*   Updated: 2025/12/03 21:42:15 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include <stdio.h>

void	load_texture(t_game *a)
{
	int	width;
	int	height;

	a->img_collectible = mlx_xpm_file_to_image(a->mlx_connection, "assets/collectible.xpm", &width, &height);
	if (!a->img_collectible)
		return ;
	a->img_player = mlx_xpm_file_to_image(a->mlx_connection, "assets/perso.xpm", &width, &height);
	if (!a->img_player)
		return (destroy_mlx(a, 1));
	a->img_exit = mlx_xpm_file_to_image(a->mlx_connection, "assets/exit.xpm", &width, &height);
	if (!a->img_exit)
		return (destroy_mlx(a, 2));
	a->img_wall = mlx_xpm_file_to_image(a->mlx_connection, "assets/wall.xpm", &width, &height);
	if (!a->img_wall)
		return (destroy_mlx(a, 3));
	a->img_floor = mlx_xpm_file_to_image(a->mlx_connection, "assets/floor.xpm", &width, &height);
	if (!a->img_floor)
		return (destroy_mlx(a, 4));
}

void	call_texture(t_game *a, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(a->mlx_connection, a->mlx_window, a->img_floor, x * 64, y * 64);
	if (c == 'P')
	{
		mlx_put_image_to_window(a->mlx_connection, a->mlx_window, a->img_floor, x * 64, y * 64);
		mlx_put_image_to_window(a->mlx_connection, a->mlx_window, a->img_player, x * 64, y * 64);
	}
	if (c == 'C')
	{
		mlx_put_image_to_window(a->mlx_connection, a->mlx_window, a->img_floor, x * 64, y * 64);
		mlx_put_image_to_window(a->mlx_connection, a->mlx_window, a->img_collectible,x * 64, y * 64);
	}
	if (c == 'E')
	{
		mlx_put_image_to_window(a->mlx_connection, a->mlx_window, a->img_floor, x * 64, y * 64);
		mlx_put_image_to_window(a->mlx_connection, a->mlx_window, a->img_exit, x * 64, y * 64);
	}
}

void	make_texture(t_game *a)
{
	int	x;
	int	y;

	y = 0;
	while (a->map[y] != NULL)
	{
		x = 0;
		while (a->map[y][x] != '\n' && a->map[y][x] != '\0')
		{
			if (a->map[y][x] == '1')
			{
				mlx_put_image_to_window(a->mlx_connection, a->mlx_window, a->img_wall, x * 64, y * 64);
			}
			else if (a->map[y][x] == '0')
				mlx_put_image_to_window(a->mlx_connection, a->mlx_window, a->img_floor, x * 64, y * 64);
			else if (a->map[y][x] == 'P')
				call_texture(a, 'P', x, y);
			else if (a->map[y][x] == 'C')
				call_texture(a, 'C', x, y);
			else if (a->map[y][x] == 'E')
				call_texture(a, 'E', x, y);
			x++;
		}
		y++;
	}
}


int	exit_game(t_game *a)
{
	if (a->img_wall)
		mlx_destroy_image(a->mlx_connection, a->img_wall);
	if (a->img_floor)
		mlx_destroy_image(a->mlx_connection, a->img_floor);
	if (a->img_player)
		mlx_destroy_image(a->mlx_connection, a->img_player);
	if (a->img_collectible)
		mlx_destroy_image(a->mlx_connection, a->img_collectible);
	if (a->img_exit)
		mlx_destroy_image(a->mlx_connection, a->img_exit);
	if (a->mlx_window)
		mlx_destroy_window(a->mlx_connection, a->mlx_window);
	if (a->mlx_connection)
	{
		mlx_destroy_display(a->mlx_connection);
		free (a->mlx_connection);
	}
	free_tab (a->map);
	free (a);
	exit(0);
	return (0);
}

int	init_game(t_game *init)
{
	init->y = 0;
	init->height = 0;
	init->mlx_connection = mlx_init();
	if (!init->mlx_connection)
		return (1);
	init->height = my_strlen(init->map[init->y]);
	init->width = nbr_of_column(init);
	init->height = (init->height - 1) * 64;
	init->width = init->width * 64;;
	init->mlx_window = mlx_new_window(init->mlx_connection, init->height, init->width, "So_Long");
	if (!init->mlx_window)
		return (1);
	load_texture(init);
	make_texture(init);
	mlx_hook(init->mlx_window, 17, 0, exit_game, init);
	mlx_hook(init->mlx_window, 2, 1L<<0, touch_move, init);
	mlx_loop(init->mlx_connection);
	return (0);
}
