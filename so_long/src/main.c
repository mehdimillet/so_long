/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 22:49:01 by memillet          #+#    #+#             */
/*   Updated: 2025/12/03 21:42:18 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_value(t_game *init)
{
	init->fd = 0;
	init->width = 0;
	init->height = 0;
	init->count_C = 0;
	init->count_E = 0;
	init->count_P = 0;
	init->collected = 0;
	init->x = 0;
	init->y = 0;
	init->pos_x = 0;
	init->pos_y = 0;
	init->moves = 0;
	init->nbr_move = 0;
}

int	read_map(t_game *check, char *argv)
{
	char	*line;
	int		nbr_line;
	int		i;

	line = NULL;
	i = 0;
	check->fd = open(argv, O_RDONLY);
	if (check->fd == -1)
		return (ft_printf("map error\n"), 1);
	nbr_line = count_lines(check->fd);
	close(check->fd);
	check->fd = open(argv, O_RDONLY);
	check->map = malloc (sizeof(char *) * (nbr_line + 1));
	if (!check->map)
		return (1);
	while ((line = get_next_line(check->fd)) != NULL)
	{
		check->map[i] = line;
		i++;
	}
	close(check->fd);
	check->map[i] = NULL;
	get_next_line(-1);
	return (0);
}

int	ft_call_parsing(char *argv, t_game *check)
{
	char	**map_cpy;

	if (check_filename(argv) != 0)
		return (1);
	if (read_map(check, argv) != 0)
		return (1);
	if (ft_is_rectangular(check) != 0)
		return (free_tab(check->map), 1);
	if (ft_border(check) != 0)
		return (free_tab(check->map), 1);
	if (check_element(check) != 0)
		return (free_tab(check->map), 1);
	check->fd = open(argv, O_RDONLY);
	find_player(check);
	map_cpy = map_copy(check);
	flood_fill(map_cpy, check->pos_y, check->pos_x);
	if (check_flood_fill(map_cpy) != 0)
		return (free_tab(check->map), free_tab(map_cpy), 1);
	close(check->fd);
	free_tab(map_cpy);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_printf("invalid number of argument\n", 1));
	game = malloc(sizeof(t_game) + 1);
	if (!game)
		return (1);
	init_value(game);
	if (ft_call_parsing(argv[1], game) != 0)
		return (free(game), 1);
	if (init_game(game) != 0)
		return (1);
	return (0);
}
